#ifndef MAINAPP_MOCK_VIEW_H
#define MAINAPP_MOCK_VIEW_H

#include "gmock/gmock.h"
#include "include/view.h"

using Polaris::GraphConnection;
using Polaris::View;
using Polaris::Meta;

class MockView : public View
{
public:
    MOCK_METHOD2( BuildItems, void( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) );
    MOCK_METHOD1( DrawThePath, void( std::vector< size_t > path ) );
    MOCK_METHOD1( OnMetaChanged, void( const Meta & meta ) );
    MOCK_METHOD1( OnMetaAdded, void( const Meta & meta ) );
    MOCK_METHOD1( OnMetaRemoved, void( const Meta & meta ) );
    MOCK_METHOD1( OnConnectionAdded, void( const GraphConnection & connection ) );
    MOCK_METHOD1( OnConnectionRemoved, void( const GraphConnection & connection ) );

    MOCK_CONST_METHOD0( GetSelectedNode, size_t() );
    MOCK_CONST_METHOD0( GetSelectedNodes, std::pair< size_t, size_t >() );
    MOCK_CONST_METHOD0( GetNodeCoordinates, QPoint() );
    MOCK_CONST_METHOD0( GetFloorNumber, int8_t() );
};

#endif //MAINAPP_MOCK_VIEW_H
