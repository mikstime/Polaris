#include <iostream>
#include "../include/Client.h"

using namespace Polaris;

Client::Client( const Operation & operation, const Location & location )
{
    if ( operation == Operation::WRITE )
        client = new Writer( location, operation );
    else if ( operation == Operation::READ )
        client = new Reader( location, operation );
    else
        client = nullptr;
}

bool Client::FileSharing( std::string& path )
{
    return client->Exchange( path );
}

ClientAbstr::ClientAbstr( const Location & location ,
                          const Operation & operation )
{
    if ( location == Location::NETWORK )
    {
        data = new Network( operation );
        lct = Location::NETWORK;
    }
    else if ( location == Location::LOCALHOST )
    {
        data = new Localhost( operation );
        lct = Location::LOCALHOST;
    }
}

ClientImple::ClientImple( const Operation & operation ) :
        host( HOST ), port( atoi(PORT) )
{
    sock = socket( PF_INET, SOCK_STREAM, 0 );
    if (sock < 0 )
    {
        throw std::runtime_error( "Client construction failed: " +
                                  std::string( strerror( errno ) ) );
    }
    InitSockaddr();
}

void ClientImple::InitSockaddr()
{
    struct hostent * hostinfo = nullptr;
    servername.sin_family = AF_INET;
    servername.sin_port = htons( port );
    hostinfo = gethostbyname( host.c_str() );
    if ( hostinfo == nullptr)
    {
        throw std::runtime_error( "Unknown host: " +
                                  std::string( strerror( errno ) ) );
    }
    servername.sin_addr = * ( struct in_addr * )hostinfo->h_addr;
}

std::tuple<std::string, int, int> ClientImple::CollectInfo()
{
    return std::make_tuple( host, sock, port );
}

void Localhost::OpenConnection()
{
    if ( 0 > connect( sock, ( struct sockaddr * ) & servername,
                      sizeof( servername ) ) )
    {
        throw std::runtime_error( "Open connection failed: " +
                                  std::string( strerror( errno ) ) );
    }
}

void Localhost::CloseConnection()
{
    close(sock);
}

bool Reader::Exchange( std::string & path )
{

    if( lct == Location::LOCALHOST )
    {
        try
        {
            data->OpenConnection();
        }
        catch ( std::runtime_error & exception )
        {
            return false;
        }
        std::tuple<std::string, int, int> info = data->CollectInfo();
        std::string msg = "G";
        int num_bytes;
        num_bytes = send( std::get< 1 >( info ), msg.c_str(), msg.size(), 0 );
        if ( num_bytes < 0 )
        {
            throw std::runtime_error( "write failed: " +
                                      std::string( strerror( errno ) ) );
        }
        int n = ::recv( std::get< 1 >( info ), buffer, sizeof(buffer),
                        MSG_NOSIGNAL );
        if ( -1 == n && errno != EAGAIN )
            throw std::runtime_error( "read failed: " +
                                      std::string( strerror( errno ) ) );
        if ( 0 == n )
            throw std::runtime_error( "client: " + std::to_string(
                    std::get< 1 >( info ) ) + " disconnected" );
        if ( -1 == n )
            throw std::runtime_error( "client: " + std::to_string(
                    std::get< 1 >( info ) ) + " timeouted" );

        std::string returned_msg( buffer, buffer + n );
        path = returned_msg;
        /*std::ofstream fout;
        fout.open( path );
        fout.write(returned_msg.c_str(), returned_msg.size());
        fout.close();
        returned_msg.clear();*/
        data->CloseConnection();
    }
    else if (lct == Location::NETWORK)
    {
        try {
            boost::asio::io_service io;
            tcp::resolver Resolver(io);
            tcp::resolver::query Query(HOST, PORT);
            auto it = Resolver.resolve(Query);
            BClient client(io, it);
            std::thread thread(boost::bind(&boost::asio::io_service::run, &io));
            char line[Data::max_length + 1];

            size_t sent = 0;
            while (sent < path.size())
            {
                memcpy(line, path.data() + sent, 1025);
                Data msg;
                msg.SetBodyLength(std::strlen(line));
                std::memcpy(msg.GetBody(), line, msg.GetBodyLength());
                msg.Encode();
                client.Write(msg);
            }
            client.Close();
            thread.join();
            path = client.ss.str();
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << "\n";
        }
    }
    return true;
}

bool Writer::Exchange( std::string & msg )
{
    if(lct == Location::LOCALHOST)
    {
    try
    {
        data->OpenConnection();
    }
    catch (std::runtime_error & exception)
    {
        return false;
    }
    std::tuple<std::string, int, int> info = data->CollectInfo();
    int num_bytes;
    /*std::ifstream fin;
    fin.open( path );
    std::string tmp;
    while( getline( fin, tmp ) )
    {
        msg += tmp + "\n";
    }
    msg.pop_back();*/
        num_bytes = send( std::get< 1 >( info ), msg.c_str(), msg.size(), 0 );
        std::cerr << num_bytes << " sended" << std::endl;
        if ( num_bytes < 0 )
        {
            throw std::runtime_error( "write failed: " +
                                      std::string( strerror( errno ) ) );
        }
        int n = ::recv( std::get< 1 >( info ), buffer, sizeof(buffer),
                        MSG_NOSIGNAL);

        if (-1 == n && errno != EAGAIN)
            throw std::runtime_error("read failed: " + std::string(strerror(errno)));
        if (0 == n)
            throw std::runtime_error("client: " +
                                     std::to_string( std::get< 1 >( info ) ) + " disconnected");
        if (-1 == n)
            throw std::runtime_error("client: " +
                                     std::to_string( std::get< 1 >( info ) ) + " timeouted");

        std::string returned_msg( buffer, buffer + n );
        std::cerr << returned_msg << std::endl;
        data->CloseConnection();
    }
    else if (lct == Location::NETWORK)
    {
        try
        {
            boost::asio::io_service io;
            tcp::resolver Resolver(io);
            tcp::resolver::query Query(HOST, PORT);
            auto it = Resolver.resolve(Query);
            BClient client(io, it);
            std::thread thread(boost::bind(&boost::asio::io_service::run, &io));
            char line[Data::max_length + 1];
            size_t sent = 0;
            while (sent < msg.size())
            {
                memcpy(line, msg.data() + sent, 1025);
                Data msg;
                msg.SetBodyLength(std::strlen(line));
                std::memcpy(msg.GetBody(), line, msg.GetBodyLength());
                msg.Encode();
                client.Write(msg);
            }
            client.Close();
            thread.join();
            msg = client.ss.str();
        }
        catch (std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << "\n";
        }
    }
    return true;
}

BClient::BClient(boost::asio::io_service& io_service,
                 tcp::resolver::iterator endpoint_iterator):
        io(io_service), sock(io_service)
{
    boost::asio::async_connect(sock, endpoint_iterator,
                               boost::bind(&BClient::Connect, this, boost::asio::placeholders::error));
}

void BClient::Write(const Data& msg)
{
    io.post(boost::bind(&BClient::DoWrite, this, msg));
}

void BClient::Close()
{
    io.post(boost::bind(&BClient::SocketClose, this));
}

void BClient::Connect(const boost::system::error_code& error)
{
    if (!error)
    {
        boost::asio::async_read(sock,
                                boost::asio::buffer(readMsg.GetData(), Data::header_length),
                                boost::bind(&BClient::ReadHeader, this, boost::asio::placeholders::error));
    }
}

void BClient::ReadHeader(const boost::system::error_code& error)
{
    if (!error && readMsg.Decode())
    {
        boost::asio::async_read(sock,boost::asio::buffer(readMsg.GetBody(),
                                                         readMsg.GetBodyLength()),
                                boost::bind(&BClient::ReadBody, this,
                                            boost::asio::placeholders::error));
    }
    else
    {
        SocketClose();
    }
}

void BClient::ReadBody(const boost::system::error_code& error)
{
    if (!error)
    {
        ss.write(readMsg.GetBody(), readMsg.GetBodyLength());
        ss << std::endl;
        boost::asio::async_read(sock,boost::asio::buffer(readMsg.GetData(),
                                                         Data::header_length), boost::bind(&BClient::ReadHeader,
                                                                                           this, boost::asio::placeholders::error));
    }
    else
    {
        SocketClose();
    }
}

void BClient::DoWrite(Data msg)
{
    bool isWriting = !writeMsgs.empty();
    writeMsgs.push_back(msg);
    if (!isWriting)
    {
        boost::asio::async_write(sock,boost::asio::buffer(writeMsgs.front().GetData(),
                                                          writeMsgs.front().GetLength()), boost::bind(&BClient::BWrite,
                                                                                                      this, boost::asio::placeholders::error));
    }
}

void BClient::BWrite(const boost::system::error_code& error)
{
    if (!error)
    {
        writeMsgs.pop_front();
        if (!writeMsgs.empty())
        {
            boost::asio::async_write(sock, boost::asio::buffer(writeMsgs.front().GetData(),
                                                               writeMsgs.front().GetLength()), boost::bind(&BClient::BWrite, this,
                                                                                                           boost::asio::placeholders::error));
        }
    }
    else
    {
        SocketClose();
    }
}

void BClient::SocketClose()
{
    sock.close();
}