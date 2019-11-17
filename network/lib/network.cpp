#include "network.h"

void Network::Open()
{

}

void Network::Close()
{

}

void Localhost::Open()
{

}

void Localhost::Close()
{

}

void Reader::Read()
{

}

void Writer::Write()
{

}

int Engine::CreateServerSocket(uint32_t port, uint32_t listen_queue_size)
{

}

void Client::Connect(const std::string &host, int port)
{

}

void Client::Send(const std::string &s)
{

}

std::string Client::Recv()
{

}

void Client::SetRcvTimeout(int sec, int microsec)
{

}

void Client::SetNonBlocked(bool opt)
{

}

bool Client::DataAvailable()
{

}

void PollEngine::EventLoop()
{

}

void PollEngine::Run()
{

}

int PollEngine::Prepare(struct pollfd *fds)
{

}

void Server::CreateServerSocket(uint32_t port, uint32_t queue_size)
{

}

std::shared_ptr<Client> Server::Accept()
{

}

void Server::SetNonBlocked(bool opt)
{

}
