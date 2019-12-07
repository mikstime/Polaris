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

bool Client::FileSharing(const std::string& path)
{
    return client->Exchange( path );
}

Operation ClientAbstr::GetOperation()
{
    return data->GetOperation();
}

ClientAbstr::ClientAbstr( const Location & location , const Operation & operation)
{
    if ( location == Location::NETWORK )
    {
        data = new Network(operation);
        lct = Location::NETWORK;
    }
    else if ( location == Location::LOCALHOST )
    {
        data = new Localhost(operation);
        lct = Location::LOCALHOST;
    }
    else
    {
        data = nullptr;
    }
}

Operation ClientImple::GetOperation()
{
    return opr;
}

Network::Network( const Operation & operation )
{
    opr = operation;

    sock = -1;
    port = 8080;
    host = "127.0.0.1";
}

int Network::OpenConnection()
{
    sock = socket( PF_INET, SOCK_STREAM, 0 );
    struct sockaddr_in servername {};
    if (sock < 0 )
    {
        perror( "socket (client)" );
        exit( EXIT_FAILURE );
    }
    InitSockaddr( & servername, host.c_str(), port );
    if ( 0 > connect( sock, ( struct sockaddr * ) & servername, sizeof( servername ) ) )
    {
        perror( "connect (client)" );
        exit( EXIT_FAILURE );
    }
    return 0;
}

int Network::CloseConnection()
{
        return close(sock);
}

int Network::GetDeskriptor()
{
    return sock;
}

void Network::InitSockaddr(struct sockaddr_in * name, const char* hostname, int port)
{
    struct hostent * hostinfo;
    name->sin_family = AF_INET;
    name->sin_port = htons(port);
    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        fprintf(stderr, "Unknown host %s.\n", hostname);
        exit(EXIT_FAILURE);
    }
    name->sin_addr = *(struct in_addr*)hostinfo->h_addr;
}

const std::string & Network::GetPath()
{
    return nullptr;
}

Localhost::Localhost( const Operation & operation )
{
    opr = operation;
}

int Localhost::OpenConnection()
{
    return 1;
}

int Localhost::CloseConnection()
{
    return 1;
}

int Localhost::GetDeskriptor()
{
    return 0;
}

const std::string & Localhost::GetPath()
{
    return file;
}

bool Reader::Exchange( const std::string & path )
{
    if(data->OpenConnection() != 1)
        return false;
    if(lct == Location::LOCALHOST)
    {
        std::ifstream source;
        source.open(path);
        std::ofstream fin;
        fin.open(data->GetPath());
        std::string msg;
        std::string tmp;
        while( getline( source, tmp ) )
        {
            msg += tmp;
        }
        fin.write(msg.c_str(), msg.size());
        data->CloseConnection();
        return true;
    }
    else if (lct == Location::NETWORK)
    {
        int count;
        std::string msg = "G";
        count = write(data->GetDeskriptor(), msg.c_str(), msg.size() + 1);
        if (count < 0)
            throw std::runtime_error("write failed: " + std::string(strerror(errno)));
        std::cerr << "write message " << msg << " to socket" << std::endl;

        char buf[1024];
        int n = ::recv(data->GetDeskriptor(), buf, sizeof(buf), MSG_NOSIGNAL);

        if (-1 == n && errno != EAGAIN)
            throw std::runtime_error("read failed: " + std::string(strerror(errno)));
        if (0 == n)
            throw std::runtime_error("client: " + std::to_string(data->GetDeskriptor()) +
                                     " disconnected");
        if (-1 == n)
            throw std::runtime_error("client: " + std::to_string(data->GetDeskriptor()) +
                                     " timeouted");

        std::string ret(buf, buf + n);
        while (ret.back() == '\r' || ret.back() == '\n')
            ret.pop_back();
        std::cerr << "client: " << data->GetDeskriptor() << ", recv: \n"
                  << ret << " [" << n << " bytes]" << std::endl;
        std::ifstream source;
        source.open(path);
        std::ofstream fin;
        data->CloseConnection();
        return true;
    }
    data->CloseConnection();
    return false;
}

bool Writer::Exchange( const std::string & path )
{

    if(data->OpenConnection() == -1)
        return false;
    if(lct == Location::LOCALHOST)
    {
        std::ofstream fout;
        fout.open(data->GetPath());
        std::ifstream source;
        source.open(path);
        std::string msg;
        std::string tmp;
        while( getline( source, tmp ) )
        {
            msg += tmp;
        }
        data->CloseConnection();
        return true;
    }
    else if (lct == Location::NETWORK)
    {
        int nbytes;
        char buffer[1024];
        source.read(buffer, 1024);
        nbytes = write((int)data->GetDeskriptor(), buffer, strlen(buffer) + 1);
        if (nbytes < 0)
        {
            data->CloseConnection();
            return false;
        }
        std::cerr << "write message to socket \n" << std::endl;
        data->CloseConnection();
        return true;
    }
    data->CloseConnection();
    return false;
}
