#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QVector>

struct GraphNode {}; // Структура комнаты

namespace Polaris
{

class FileHandler
{
public:
    FileHandler();
    bool FileRead( QVector< GraphNode > * graph );
    bool FileWrite( QVector< GraphNode > * graph );
};

} // namespace Polaris

#endif // FILEHANDLER_H
