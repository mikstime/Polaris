#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "data.h"

using boost::asio::ip::tcp;

class User
{
public:
    virtual ~User() {}
    virtual void Deliver(const Data& msg) = 0;
};


class ClientNet
{
public:
    void Join(boost::shared_ptr<User> member);
    void Disconect(boost::shared_ptr<User> member);
    void Deliver(const Data& msg);

private:
    std::set<boost::shared_ptr<User>> members;
    enum { recent_msgs = 100 };
    std::deque<Data> recentMsgs;
};

void ClientNet::Join(boost::shared_ptr<User> member)
{
    members.insert(member);
    std::for_each(recentMsgs.begin(), recentMsgs.end(),
                  boost::bind(&User::Deliver, member, _1));
}

void ClientNet::Disconect(boost::shared_ptr<User> member)
{
    members.erase(member);
}

void ClientNet::Deliver(const Data& msg)
{
    recentMsgs.push_back(msg);
    while (recentMsgs.size() > recent_msgs)
        recentMsgs.pop_front();

    std::for_each(members.begin(), members.end(),
                  boost::bind(&User::Deliver, _1, boost::ref(msg)));
}

class Session: public User, public boost::enable_shared_from_this<Session>
{
public:
    Session(boost::asio::io_service& io_service, ClientNet& friends);
    tcp::socket& Socket();
    void Start();
    void Deliver(const Data& msg);
    void ReadHeader(const boost::system::error_code& error);
    void ReadBody(const boost::system::error_code& error);
    void Write(const boost::system::error_code& error);

private:
    tcp::socket sock;
    ClientNet& net;
    Data readMsg;
    std::deque<Data> writeMsgs;
};

Session::Session(boost::asio::io_service& io_service, ClientNet& friends):
                sock(io_service), net(friends) {}

tcp::socket& Session::Socket()
{
    return sock;
}

void Session::Start()
{
    net.Join(shared_from_this());
    boost::asio::async_read(sock, boost::asio::buffer(readMsg.GetData(),
            Data::header_length),boost::bind(&Session::ReadHeader,
                    shared_from_this(), boost::asio::placeholders::error));
}

void Session::Deliver(const Data& msg)
{
    bool write_in_progress = !writeMsgs.empty();
    writeMsgs.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(sock, boost::asio::buffer(writeMsgs.front().GetData(),
                writeMsgs.front().GetLength()), boost::bind(&Session::Write, shared_from_this(),
                        boost::asio::placeholders::error));
    }
}

void Session::ReadHeader(const boost::system::error_code& error)
{
    if (!error && readMsg.Decode())
    {
        boost::asio::async_read(sock, boost::asio::buffer(readMsg.GetBody(),
                readMsg.GetBodyLength()),boost::bind(&Session::ReadBody,
                        shared_from_this(), boost::asio::placeholders::error));
    }
    else
    {
        net.Disconect(shared_from_this());
    }
}

void Session::ReadBody(const boost::system::error_code& error)
{
    if (!error)
    {
        net.Deliver(readMsg);
        boost::asio::async_read(sock, boost::asio::buffer(readMsg.GetData(),
                Data::header_length), boost::bind(&Session::ReadHeader,
                        shared_from_this(), boost::asio::placeholders::error));
    }
    else
    {
        net.Disconect(shared_from_this());
    }
}

void Session::Write(const boost::system::error_code& error)
{
    if (!error)
    {
        writeMsgs.pop_front();
        if (!writeMsgs.empty())
        {
            boost::asio::async_write(sock, boost::asio::buffer(writeMsgs.front().GetData(),
                    writeMsgs.front().GetLength()),boost::bind(&Session::Write,
                            shared_from_this(), boost::asio::placeholders::error));
        }
    }
    else
    {
        net.Disconect(shared_from_this());
    }
}

class Server
{
public:
    Server(boost::asio::io_service& io, const tcp::endpoint& endpoint);
    void Accept();
    void UserAccept(boost::shared_ptr<Session> session, const boost::system::error_code& error);

private:
    boost::asio::io_service& serverIO;
    tcp::acceptor acceptor;
    ClientNet net;
};

Server::Server(boost::asio::io_service& io,
const tcp::endpoint& endpoint)
: serverIO(io),
acceptor(io, endpoint)
{
    Accept();
}

void Server::Accept()
{
    boost::shared_ptr<Session> new_session(new Session(serverIO, net));
    acceptor.async_accept(new_session->Socket(), boost::bind(&Server::UserAccept,
            this, new_session, boost::asio::placeholders::error));
}

void Server::UserAccept(boost::shared_ptr<Session> session,
                const boost::system::error_code& error)
{
    if (!error)
    {
        session->Start();
    }
    Accept();
}

typedef boost::shared_ptr<Server> server_ptr;

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
        {
            return 1;
        }
        boost::asio::io_service io;
        std::list<server_ptr> servers;
        for (int i = 1; i < argc; ++i)
        {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            server_ptr server(new Server(io, endpoint));
            servers.push_back(server);
        }
        io.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
