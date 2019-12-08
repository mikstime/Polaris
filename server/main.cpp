#include "include/Server.h"

using namespace Polaris;

int main()
{
    int port = 8080;
    Server server( port );
    server.run();
}