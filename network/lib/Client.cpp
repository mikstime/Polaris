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

bool Client::FileSharing( const std::string& path )
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
host( HOST ), port( PORT )
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

Network::Network( const Operation & operation ) : ClientImple( operation )
{

}

void Network::OpenConnection()
{

}

void Network::CloseConnection()
{

}

Localhost::Localhost( const Operation & operation ) : ClientImple( operation )
{
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

bool Reader::Exchange( const std::string & path )
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
    if( lct == Location::LOCALHOST )
    {
        std::string msg = "G";
        int num_bytes;
        num_bytes = write( std::get< 1 >( info ), msg.c_str(), msg.size() );
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
        std::ofstream fout;
        fout.open( path );
        fout.write(returned_msg.c_str(), returned_msg.size());
        fout.close();
        returned_msg.clear();
    }
    else if (lct == Location::NETWORK)
    {

    }
    data->CloseConnection();
    return true;
}

bool Writer::Exchange( const std::string & path )
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
    if(lct == Location::LOCALHOST)
    {

    }
    else if (lct == Location::NETWORK)
    {
        std::string msg;
        int num_bytes;
        std::ifstream fin;
        fin.open( path );
        std::string tmp;
        while( getline( fin, tmp ) )
        {
            msg += tmp + "\n";
        }
        msg.pop_back();
        num_bytes = write( std::get< 1 >( info ), msg.c_str(), msg.size() );
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
    }
    data->CloseConnection();
    return true;
}
