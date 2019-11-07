#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QVector>
#include <include/mainwindow.h>

namespace Polaris
{

class CFileHandler
{
public:
    CFileHandler();
    bool FileRead(QVector<SGraphNode> *graph);
    bool FileWrite(QVector<SGraphNode> *graph);
};

}

#endif // FILEHANDLER_H
