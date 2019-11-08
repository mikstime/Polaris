#ifndef HER_H
#define HER_H

#include <QObject>

struct GraphNode {};
struct GraphConnection {};

class her : public QObject
{
    Q_OBJECT
public:
    explicit her(QObject *parent = nullptr);

public slots:
   void SetSelectedNodes( int node_id );
};

#endif // HER_H
