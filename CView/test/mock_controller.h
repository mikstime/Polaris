#ifndef MOCK_CONTROLLER_H
#define MOCK_CONTROLLER_H

#include "gmock/gmock.h"
#include "include/graphic_view.h"

class MockController
{
public:
    MOCK_CONST_METHOD0( GetSelectedNode, void() );
    MOCK_CONST_METHOD0( GetSelectedNodes, void() );
    MOCK_CONST_METHOD0( GetNodeCoordinates, void() );
    MOCK_CONST_METHOD0( GetFloorNumber, void() );

    MOCK_CONST_METHOD1( SetSelectedNode, void( const size_t node_id ) );
    MOCK_CONST_METHOD2( SetSelectedNodes, void( const size_t a_node_id, const size_t b_node_id ) );
    MOCK_CONST_METHOD1( SetNodeCoordinates, void( const QPoint point ) );
    MOCK_CONST_METHOD1( SetFloorNumber, void( const short int floor ) );
};

#endif // MOCK_CONTROLLER_H
