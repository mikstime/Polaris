#ifndef NETWORK_NETWORK_H
#define NETWORK_NETWORK_H

#include <sys/epoll.h>
#include <sys/errno.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <memory>
#include <vector>

namespace Polaris
{
    class DataHandlerImple;

    class DataHandler
    {
    public:
        DataHandler( DataHandlerImple * ptr ) : ptr_imp( ptr ) {}
        DataHandler() {}
        virtual ~DataHandler() = default;
        virtual void Read() = 0;
        virtual void Write() = 0;

    protected:
        DataHandlerImple * ptr_imp;

    };

    class DataHandlerImple
    {
    public:
        virtual ~DataHandlerImple() {}
        virtual void Open() = 0;
        virtual void Close() = 0;

    };

    class Network : public DataHandlerImple
    {
    public:
        void Open() override;
        void Close() override;

    };

    class Localhost : public DataHandlerImple
    {
    public:
        void Open() override;
        void Close() override;

    };

    class Reader : public DataHandler
    {
    public:
        Reader( DataHandlerImple * ptr ) : DataHandler( ptr ) {}
        void Read() override;
        
    };

    class Writer : public DataHandler
    {
    public:
        Writer( DataHandlerImple * ptr ) : DataHandler( ptr ) {}
        void Write() override;
        
    };

    enum class Client_state_t : uint8_t { WANT_READ, WANT_WRITE };

    class Engine
    {
    public:
        explicit Engine( int port ) : m_Listener( port ) {}
        virtual void Run() = 0;
        int Listener() const { return m_Listener; }
        
    private:
        int m_Listener;
        int CreateServerSocket( uint32_t port, uint32_t listen_queue_size );
        
    };

    class Client
    {
    public:
        Client( int _sd ) : _sd(_ sd ) {}
        ~Client()
        { if ( _sd > 0 ) close( _sd ); }
        void Connect( const std::string & host, int port );
        void Send( const std::string & s );
        std::string Recv();
        void SetRcvTimeout( int sec, int microsec );
        void SetNonBlocked( bool opt );
        bool DataAvailable();
        
    private:
            int _sd;
        
    };

    class PollEngine: public Engine
    {
    public:
        explicit PollEngine(int port): Engine(port) {}
        void Run() override;
        int Prepare(struct pollfd *fds);
        
    private:
        std::vector< Client > m_Clients;
        void EventLoop();
        
    };

    class Server
    {
    public:
        Server() : m_Sd( -1 ) {}
        ~Server() { if ( m_Sd > 0 ) close( m_Sd ); }
        void CreateServerSocket( uint32_t port, uint32_t queue_size );
        std::shared_ptr< Client > Accept() ;
        void SetNonBlocked( bool opt );
        
    private:
        int m_Sd;
        
    };
}

#endif //NETWORK_NETWORK_H
