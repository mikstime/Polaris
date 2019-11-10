#ifndef MOCK_CONTROLLER_H
#define MOCK_CONTROLLER_H

#include "gmock/gmock.h"
#include "include/cgraphics_view.h"

#include <QObject>

class FakeController : public QObject
{
public:
    virtual void SetSelectedNodes( int node_id ) = 0;
    virtual void SetSelectedConnection( int connection_id ) = 0;
    virtual void SaveChangedData( GraphNode node ) = 0;
    virtual void SaveConnection( GraphConnection connection ) = 0;
};

class MockController : public FakeController
{
public:
    MOCK_METHOD1( SetSelectedNodes, void( int node_id ) );
    MOCK_METHOD1( SetSelectedConnection, void( int connection_id ) );
    MOCK_METHOD1( SaveChangedData, void( GraphNode node ) );
    MOCK_METHOD1( SaveConnection, void( GraphConnection connection ) );
};

#endif // MOCK_CONTROLLER_H
