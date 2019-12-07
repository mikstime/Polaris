#ifndef SELECT_SERVER_H
#define SELECT_SERVER_H

#include <cerrno>
#include <fcntl.h>
#include <netinet/in.h>
#include <cstdio>
#include <sys/socket.h>
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <stdexcept>
#include <fstream>

namespace Polaris
{
    class Engine
    {
        int m_Listener;
        int CreateServerSocket( int port );
    public:
        explicit Engine( int port );
        void NonBlocked( int sd, bool opt ) noexcept( false );
        virtual void run() = 0;
        int Listener() const;
    };

    class Server: public Engine
    {
    public:
        explicit Server( int port );
        void run() override;
    private:
        void Prepare( fd_set *read_fds );
        void EventLoop();
        std::set< int > Clients;
    };
}
#endif //SELECT_SERVER_H
