#ifndef NET_CLIENT_H
#define NET_CLIENT_H

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
        ~Client() {}

    private:
        ClientAbstr * client;
    };

    class ClientAbstr
    {
    public:
        ClientAbstr( const Location & location );
        virtual ~ClientAbstr() = default;
        int CreateSocket();
        virtual bool Exchange() = 0;

    protected:
        int sock;
        ClientImple * data;
    };

    class ClientImple
    {
    public:
        virtual ~ClientImple() {};
        virtual int OpenConnection() = 0;
        virtual int CloseConnection() = 0;

    };

    class Network : public ClientImple
    {
    public:
        Network();
        ~Network() {}
        int OpenConnection();
        int CloseConnection();

    };

    class Localhost : public ClientImple
    {
    public:
        Localhost();
        ~Localhost() {}
        int OpenConnection();
        int CloseConnection();

    };

    class Reader : public ClientAbstr
    {
    public:
        Reader( const Location & location ) : ClientAbstr( location ) {}
        bool Exchange();

    };

    class Writer : public ClientAbstr
    {
    public:
        Writer( const Location & location ) : ClientAbstr( location ) {}
        bool Exchange();

    };

}

#endif //NET_CLIENT_H
