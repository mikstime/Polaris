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

namespace Polaris
{
    enum class Location;
    enum class Operation;
    class ClientImple;
    class ClientAbstr;
    class Client;

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
        bool FileSharing( const std::string & path );

    private:
        ClientAbstr * client;
    };

    class ClientAbstr
    {
    public:
        ClientAbstr( const Location & location, const Operation & operation );
        virtual ~ClientAbstr() = default;
        virtual bool Exchange(  const std::string & path  ) = 0;
        Operation GetOperation();

    protected:
        ClientImple * data;
        Location lct;

    };

    class ClientImple
    {
    public:
        virtual ~ClientImple() = default;;
        virtual int OpenConnection() = 0;
        virtual int CloseConnection() = 0;
        virtual int GetDeskriptor() = 0;
        virtual const std::string & GetPath() = 0;
        Operation GetOperation();

    protected:
        Operation opr;

    };

    class Network : public ClientImple
    {
    public:
        explicit Network( const Operation & operation );
        ~Network() override = default;
        int OpenConnection() override;
        int CloseConnection() override;
        const std::string & GetPath() override;
        int GetDeskriptor() override;
        void InitSockaddr(struct sockaddr_in * name, const char * hostname, int port);

    private:
        std::string host;
        int sock;
        int port;

    };

    class Localhost : public ClientImple
    {
    public:
        explicit Localhost( const Operation & operation );
        ~Localhost() override = default;
        int OpenConnection() override;
        int CloseConnection() override;
        int GetDeskriptor() override;
        const std::string & GetPath() override;

    private:
        std::string file;
      
    };

    class Reader : public ClientAbstr
    {
    public:
        Reader( const Location & location, const Operation & operation  ) : ClientAbstr( location, operation ) {}
        bool Exchange( const std::string & path  ) override;

    };

    class Writer : public ClientAbstr
    {
    public:
        Writer( const Location & location, const Operation & operation ) : ClientAbstr( location, operation ) {}
        bool Exchange( const std::string & path  ) override;

    };

}

#endif //NET_CLIENT_H
