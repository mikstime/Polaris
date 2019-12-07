#include "../include/Server.h"

using namespace Polaris;

int Engine::CreateServerSocket( int port )
{
    int sock = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
    int yes = 1;
    if ( setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof( int ) ) == -1 )
    {
        ::close( sock );
    }
    if ( sock < 0 )
    {
        perror( "socket" );
        exit( EXIT_FAILURE );
    }
    struct sockaddr_in servername {};
    memset( & servername, 0, sizeof( servername ) );
    servername.sin_family = AF_INET;
    servername.sin_port = htons( port );
    servername.sin_addr.s_addr = htonl( INADDR_ANY );
    if ( bind( sock, ( struct sockaddr * ) & servername, sizeof( servername ) ) < 0 )
    {
        perror( "bind" );
        exit( EXIT_FAILURE );
    }
    if ( ::listen( sock, 3 ) < 0 )
    {
        perror( "listen" );
        exit( EXIT_FAILURE );
    }
    m_Listener = sock;
    NonBlocked( m_Listener, true );
}

Engine::Engine(int port)
{
    CreateServerSocket( port );
}

void Engine::NonBlocked( int sd, bool opt ) noexcept(false)
{
    int f1 = fcntl( sd, F_GETFL, 0 );
    int f2 = ( opt ) ? ( f1 | O_NONBLOCK ) : ( f1 & ~O_NONBLOCK );
    if ( fcntl( sd, F_SETFL, f2 ) == -1 )
        throw std::runtime_error( "make nonblocked: " + std::string( strerror( errno ) ) );
}

int Engine::Listener() const
{
    return m_Listener;
}

Server::Server(int port) : Engine(port)
{
    Clients.clear();
}

void Server::run()
{
    EventLoop();
}

void Server::Prepare( fd_set *read_fds )
{
    FD_ZERO( read_fds );
    FD_SET( Listener(), read_fds );
    for ( auto Client: Clients )
        FD_SET( Client, read_fds );
}

void Server::EventLoop()
{
    char buf[ 1024 ];
    int size_of_data = 1;
    while ( true )
    {
        fd_set read_fds;
        Prepare( & read_fds );
        timeval session;
        session.tv_sec = 60;
        session.tv_usec = 0;
        int fd_mx = Listener();
        if ( !Clients.empty() )
            fd_mx = std::max( Listener(), * max_element( Clients.begin(), Clients.end() ) );
        if ( select( fd_mx + 1, & read_fds, nullptr, nullptr, & session ) <= 0 )
        {
            perror( "select" );
            exit( 3 );
        }
        if ( FD_ISSET( Listener(), &read_fds ) )
        {
            printf( "request received. accept it\n" );
            int sock = accept( Listener(), nullptr, nullptr );
            if ( sock < 0 )
            {
                perror( "accept" );
                exit( 3 );
            }
            printf( "request accepted\n" );
            NonBlocked( sock, true );
            Clients.insert( sock );
        }
        for ( auto client: Clients )
        {
            if ( FD_ISSET( client, & read_fds ) )
            {
                size_of_data = recv( client, buf, 1024, 0);
                if ( size_of_data <= 0 )
                {
                    close( client );
                    Clients.erase( client );
                    if ( Clients.empty() )
                        break;
                    continue;
                }
                if( buf[ 0 ] == 'G' )
                {
                    std::ifstream fin;
                    fin.open( "data.txt" );
                    std::string msg;
                    std::string tmp;
                    char c;
                    while( getline( fin, tmp ) )
                    {
                        msg += tmp;
                    }
                    size_t left = msg.size();
                    ssize_t sent = 0;
                    while ( left > 0 )
                    {
                        sent = ::send( client, msg.data() + sent, msg.size() - sent, 0 );
                        if ( -1 == sent )
                            throw std::runtime_error( std::string( strerror( errno ) ) );
                        left -= sent;
                    }
                }
                else
                {
                    std::string data_from_socket( buf, buf + size_of_data );
                    std::ofstream fout;
                    fout.open( "data.txt" );
                    if( !fout.is_open() )
                    {
                        perror( "file" );
                        exit(3);
                    }
                    for( auto symbol : data_from_socket )
                        fout << symbol;
                    fout.close();
                    std::string str = "SUCCESS";
                    send( client, str.c_str(), str.size(), 0 );
                }
            }
        }
    }
}
