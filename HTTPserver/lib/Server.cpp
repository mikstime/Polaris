#include <iostream>
#include "../include/Server.h"

Server::Server( int port ) : port( port )
{
    CreateSocket( port );
}

void * Server::GetClientAddr( struct sockaddr * client )
{
    if ( client->sa_family == AF_INET )
    {
        return & ( ( ( struct sockaddr_in * )client )->sin_addr );
    }
    return & ( ( ( struct sockaddr_in6 * )client )->sin6_addr );
}

void Server::CreateSocket( int port )
{
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct addrinfo *connections;
    memset( & hints, 0, sizeof( hints ) );
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE;
    if( getaddrinfo( nullptr, std::to_string( port ).c_str(), & hints, &servinfo) != 0 )
    {
        std::cerr << "Error in getting address" << std::endl;
        exit( EXIT_FAILURE );
    }
    int yes;
    for( connections = servinfo; connections != nullptr; connections = connections->ai_next )
    {
        sock = socket( connections->ai_family, connections->ai_socktype, connections->ai_protocol );
        if( sock == -1 )
            continue;
        if ( setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1 )
        {
            std::cerr << "Error in setting sockopt" << std::endl;
            close( sock );
            freeaddrinfo( servinfo );
            exit( EXIT_FAILURE );
        }
        if( bind( sock, connections->ai_addr, connections->ai_addrlen ) == -1 )
        {
            close( sock );
            continue;
        }
        break;
    }

    freeaddrinfo( servinfo );

    if( connections == nullptr )
    {
        std::cerr << "Failed to find address" << std::endl;
        exit( EXIT_FAILURE );
    }

    if( listen( sock, CONNECTIONS ) == -1 )
    {
        std::cerr << "Error in listening" << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Server::SendMessage( int sk, std::string & msg )
{
    std::string buffer = "HTTP/1.1 200 OK\n\n";
    buffer += msg;
    send( sk, buffer.c_str(), buffer.size(), 0 );
}

void Server::Send404( int sk )
{
    char buffer[] = "HTTP/1.1 404 \n\n";
    int len = strlen( buffer );
    send( sk, buffer, len, 0 );
}

void Server::ParseHttpRequest( std::string & msg, sHTTPHeader *header )
{
    header->type = Request::HTTP_UNKNOWN;
    int  length = msg.size();
    if( length == 3 )
    {
        if( msg[0] == 'G' && msg[1] == 'E' && msg[2] == 'T' )
            header->type = Request::HTTP_GET;
        memcpy( header->path, msg.c_str() + 3, msg.size() - 3 );
    }
}

void Server::HttpRequest( int sk )
{
    char buffer[ 1024 ];
    int num_bytes = recv( sk, buffer, 1024, 0 );
    if ( num_bytes < 0 )
    {
        std::cerr << "Error in recv" << std::endl;
        exit( EXIT_FAILURE );
    }
    std::string msg( buffer, buffer + num_bytes );
    std::cout << "request:" << std::endl << msg << std::endl;
    sHTTPHeader request;
    ParseHttpRequest( msg, &request );

    if( request.type == Request::HTTP_GET )
    {
        //SenMassage...
    }
    else
    {
        Send404( sk );
    }
}

void Server::Run()
{
    struct sockaddr_storage client;
    int curr_client;
    while( true )
    {
        socklen_t s_size = sizeof( client );
        curr_client = accept( sock, ( struct sockaddr * ) & client, & s_size );
        if( curr_client == -1 )
        {
            std::cerr << "Error in accept" << std::endl;
            exit( EXIT_FAILURE );
        }
        char ip[ INET6_ADDRSTRLEN ];
        inet_ntop( client.ss_family, GetClientAddr( ( struct sockaddr * ) & client ), ip, sizeof ip );
        HttpRequest( curr_client );
        close( curr_client );
    }
}
