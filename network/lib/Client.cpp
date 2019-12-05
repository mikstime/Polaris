#include "network/include/Client.h"

using namespace Polaris;

Client::Client( const Operation & operation, const Location & location )
{
	if ( operation == Operation::WRITE )
		client = new Writer( location );
	else if ( operation == Operation::READ )
		client = new Reader( location );
	else
		client = nullptr;
}

ClientAbstr::ClientAbstr( const Location & location )
{
	sock = -1;
	if ( location == Location::NETWORK )
    {
        data = new Network();
    }
    else if ( location == Location::LOCALHOST )
    {
        data = new Localhost();
    }
    else
    {
        data = nullptr;
    }
}

int ClientAbstr::CreateSocket()
{
	return 0;
}

Network::Network()
<<<<<<< HEAD
{
=======
{
>>>>>>> dev

}

int Network::OpenConnection()
{
	return 0;
}

int Network::CloseConnection()
{
	return 0;
}

Localhost::Localhost()
<<<<<<< HEAD
{
=======
{
>>>>>>> dev

}

int Localhost::OpenConnection()
{
	return 0;
}

int Localhost::CloseConnection()
{
	return 0;
}

bool Reader::Exchange()
<<<<<<< HEAD
{
=======
{
>>>>>>> dev
	return true;
}

bool Writer::Exchange()
<<<<<<< HEAD
{
=======
{
>>>>>>> dev
	return true;
}