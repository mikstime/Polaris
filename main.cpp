#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <limits>
#include <boost/filesystem.hpp>
using namespace std::placeholders;
using tcp = boost::asio::ip::tcp;
namespace fs = boost::filesystem;

boost::asio::io_service io;
tcp::socket sock{ io };
std::ifstream ifs;
unsigned long long fileSize;
unsigned long long sentFileBody = 0;
char buf[4096];
boost::asio::streambuf sBuf;
std::istream istr{ &sBuf };


void handleWriteBody(boost::system::error_code const& ec, std::size_t bytesTransferred)
{
    if (ec)
    {
        throw std::runtime_error{ "handleWriteBody() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }
    sentFileBody += bytesTransferred;
    if (ifs)
    {
        //ifs.read(buf, std::size(buf));
        ifs.read(buf, 4096);
        boost::asio::async_write(sock, boost::asio::buffer(buf, ifs.gcount()), handleWriteBody);
    }
    else
    {
        if (sentFileBody != fileSize)
        {
            throw std::runtime_error{ "handleWriteBody(): sentFileBody != fileSize\n" };
        }
        std::cout << "sentFileBody: " << sentFileBody << std::endl;
        std::cout << "OK" << std::endl;
    }

}

void handleWriteHeader(boost::system::error_code const& ec, std::size_t bytesTransferred)
{
    if (ec)
    {
        throw std::runtime_error{ "handleWriteHeader() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }
    ifs.read(buf, 4096);
    boost::asio::async_write(sock, boost::asio::buffer(buf, ifs.gcount()), handleWriteBody);
}

void handleReadUntil(boost::system::error_code const& ec, std::size_t bytesTransferred)
{
    if (ec && ec != boost::asio::error::eof)
    {
        throw std::runtime_error{ "handleReadUntil() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }

    std::string filePath;
    std::getline(istr, filePath, '\r');
    istr.ignore(std::numeric_limits<std::streamsize>::max());

    ifs.open(filePath.c_str(), std::ios::binary);
    if (!ifs.is_open())
    {
        throw std::runtime_error{ "handleReadUntil() : Unable to open input file: " + filePath };
    }
    fileSize = fs::file_size(filePath);
    std::cout << "fileSize: " << fileSize << std::endl;
    std::stringstream ss{ "FileName: " + fs::path{ filePath }.filename().string() + "\r\n" + "FileSize: " + std::to_string(fileSize) + "\r\n\r\n" };
    ss.getline(buf, 4096, '*');
    boost::asio::async_write(sock, boost::asio::buffer(buf, ss.str().size()), handleWriteHeader);
}

void handleAccept(boost::system::error_code const& ec)
{
    if (ec)
    {
        throw std::runtime_error{ "handleAccept() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }
    std::cout << "Client accepted\n";
    boost::asio::async_read_until(sock, sBuf, "\r\n\r\n", handleReadUntil);
}

int main()
{
    std::cout << "Server\n";
    try
    {
        tcp::acceptor acc{ io, tcp::endpoint{ tcp::v4(), 8080 } };
        acc.async_accept(sock, handleAccept);
        io.run();

        sock.shutdown(tcp::socket::shutdown_both);
        sock.close();
        acc.close();
        ifs.close();
    }
    catch (std::exception const& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
}