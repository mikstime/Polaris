#ifndef MOCK_CONTROLLER_H
#define MOCK_CONTROLLER_H

#include <QObject>
#include "include/cgraphics_view.h"

class MockController : public QObject
{
    Q_OBJECT
 public slots:
    void SetSelectedNodes( int node_id );
    void SetSelectedConnection( int connection_id );
    void SaveChangedData( GraphNode node );
    void SaveConnection( GraphConnection connection );
};

#endif // MOCK_CONTROLLER_H
