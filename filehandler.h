#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QVector>
#include <mainwindow.h>

class FileHandler
{
public:
    FileHandler();
    bool FileRead(QVector<GraphNode> *graph);
    bool FileWrite(QVector<GraphNode> *graph);
};

#endif // FILEHANDLER_H
