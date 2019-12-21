#ifndef HTTPSERVER_SERVER_H
#define HTTPSERVER_SERVER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cerrno>
#include <netdb.h>
#include <unistd.h>
#include <ctime>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8000
#define CONNECTIONS 1000

enum class Request
{
    HTTP_UNKNOWN
    ,HTTP_GET
    ,HTTP_POST
};

struct sHTTPHeader
{
    Request type;
    char path[ 255 ];
};

class Server
{
public:
    explicit Server( int port );
    ~Server()= default;
    void SendMessage( int sk, std::string & msg );
    void Send404( int sk );
    void ParseHttpRequest( std::string & msg, sHTTPHeader *apHeader );
    void HttpRequest( int sk );
    void Run();

private:
    void * GetClientAddr( struct sockaddr * );
    void CreateSocket( int port );
    int sock;
    int port;

};

#endif //HTTPSERVER_SERVER_H
