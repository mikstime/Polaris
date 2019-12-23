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


void WriteBody(boost::system::error_code const& ec, std::size_t bytesTransferred)
{
    if (ec)
    {
        throw std::runtime_error{ "writeBody() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }
    sentFileBody += bytesTransferred;
    if (ifs)
    {
        ifs.read(buf, 4096);
        boost::asio::async_write(sock, boost::asio::buffer(buf, ifs.gcount()), WriteBody);
    }
    else
    {
        if (sentFileBody != fileSize)
        {
            throw std::runtime_error{ "writeBody(): sentFileBody != fileSize\n" };
        }
        std::cout << "OK" << std::endl;
    }

}

void WriteHeader(boost::system::error_code const& ec, std::size_t bytesTransferred)
{
    if (ec)
    {
        throw std::runtime_error{ "handleWriteHeader() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }
    ifs.read(buf, 4096);
    boost::asio::async_write(sock, boost::asio::buffer(buf, ifs.gcount()), WriteBody);
}

void ReadUntil(boost::system::error_code const& ec, std::size_t bytesTransferred)
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
    std::stringstream ss{ "FileName: " + fs::path{ filePath }.filename().string() + "\r\n" + "FileSize: " + std::to_string(fileSize) + "\r\n\r\n" };
    ss.getline(buf, 4096, '*');
    boost::asio::async_write(sock, boost::asio::buffer(buf, ss.str().size()), WriteHeader);
}

void Accept(boost::system::error_code const& ec)
{
    if (ec)
    {
        throw std::runtime_error{ "handleAccept() : " + std::to_string(ec.value()) + ", " + ec.message() };
    }
    boost::asio::async_read_until(sock, sBuf, "\r\n\r\n", ReadUntil);
}

int main()
{
    try
    {
        tcp::acceptor acc{ io, tcp::endpoint{ tcp::v4(), 8080 } };
        acc.async_accept(sock, Accept);
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
