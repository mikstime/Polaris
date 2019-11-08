#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

struct GraphNode {}; // Структура комнаты

namespace Polaris
{

class FileHandler
{
public:
    FileHandler();
    bool FileRead( std::vector< GraphNode > & graph, std::string file_name );
    bool FileWrite( std::vector< GraphNode > & graph, std::string file_name );
};

} // namespace Polaris

#endif // FILEHANDLER_H
