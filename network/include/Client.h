#ifndef NET_CLIENT_H
#define NET_CLIENT_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <cerrno>
#include <fcntl.h>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <deque>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "data.h"
#include <thread>

using boost::asio::ip::tcp;

namespace Polaris
{
    enum class Location;
    enum class Operation;
    class ClientImple;
    class ClientAbstr;
    class Client;
    class Reader;
    class Writer;

#define PORT "8080"
#define HOST "127.0.0.1"

    enum class Location
    {
        LOCALHOST,
        NETWORK
    };

    enum class Operation
    {
        READ,
        WRITE
    };

    class Client
    {
    public:
        Client( const Operation & operation, const Location & location );
        ~Client() = default;
        bool FileSharing( std::string & path );

    private:
        ClientAbstr * client;

    };

    class ClientAbstr
    {
    public:
        ClientAbstr( const Location & location, const Operation & operation );
        virtual ~ClientAbstr() = default;
        virtual bool Exchange( std::string & path ) = 0;

    protected:
        ClientImple * data;
        Location lct;
        char buffer[1024];

    };

    class ClientImple
    {
    public:
        explicit ClientImple( const Operation & operation );
        virtual ~ClientImple() = default;;
        virtual void OpenConnection() = 0;
        virtual void CloseConnection() = 0;
        void InitSockaddr();
        std::tuple<std::string, int, int> CollectInfo();

    protected:
        std::string host;
        int sock;
        int port;
        struct sockaddr_in servername;
    };

    class Network : public ClientImple
    {
    public:
        explicit Network( const Operation & operation ) : ClientImple( operation ){}
        ~Network() override = default;
        void OpenConnection() override{}
        void CloseConnection() override{}

    private:

    };

    class Localhost : public ClientImple
    {
    public:
        explicit Localhost( const Operation & operation ) : ClientImple( operation ){}
        ~Localhost() override = default;
        void OpenConnection() override;
        void CloseConnection() override;

    private:

    };

    class Reader : public ClientAbstr
    {
    public:
        Reader( const Location & location, const Operation & operation  ):
                ClientAbstr( location, operation ) {}
        bool Exchange( std::string & path  ) override;

    };

    class Writer : public ClientAbstr
    {
    public:
        Writer( const Location & location, const Operation & operation ) :
                ClientAbstr( location, operation ) {}
        bool Exchange( std::string & path  ) override;

    };

    class BClient
    {
    public:
        BClient(boost::asio::io_service& io_service,
                tcp::resolver::iterator endpoint_iterator);
        void Write(const Data& msg);
        void Close();

    private:

        void Connect(const boost::system::error_code& error);
        void ReadHeader(const boost::system::error_code& error);
        void ReadBody(const boost::system::error_code& error);
        void DoWrite(Data msg);
        void BWrite(const boost::system::error_code& error);
        void SocketClose();

        boost::asio::io_service& io;
        tcp::socket sock;
        Data readMsg;
        std::deque<Data> writeMsgs;
    };

}

#endif //NET_CLIENT_H