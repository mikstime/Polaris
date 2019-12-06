#include <gtest/gtest.h>
//#include <gmock/gmock.h>
#include "include/GraphInterface/GraphInterface.h"
#include <include/Graph/Graph.h>
#include <GraphNode/GraphNode.h>
#include <GraphConnection/GraphConnection.h> // ConnectionParams
using namespace Polaris;

//class MockGraphInterface: public GraphInterface
//{
//    using Id = size_t;
//public:
//    MOCK_METHOD(void, AddNode, ( const GraphNode &), ());
//    MOCK_METHOD(void, AddNode, (Id), ());
//    MOCK_METHOD(void, AddConnection, ( const GraphNode &,
//            const GraphNode & ), ());
//    MOCK_METHOD(void, AddConnection, ( Id, Id ), ());
//    MOCK_METHOD(void, RemoveNode, ( const GraphNode & ), ());
//    MOCK_METHOD(void, RemoveNode, ( Id ), ());
//    MOCK_METHOD(bool, HasNode, ( Id ), ());
//    MOCK_METHOD(bool, HasNode, ( const GraphNode & ), ());
//    MOCK_METHOD(bool, AreConnected, ( Id, Id ), ());
//    MOCK_METHOD(bool, AreConnected, ( const GraphNode &,
//            const GraphNode & ), ());
//};
TEST( GraphInterfaceTest, AddNodesHandle )
{
    GraphInterface g;
    std::vector< GraphNode > nodes(20);
    for( int i = 0; i < 10; i++ )
    {
        g.AddNode( nodes[ i ] );
    }
    for( int i = 0; i < 10; i++ )
    {
        EXPECT_TRUE( g.HasNode( nodes[ i ] ) );
        EXPECT_TRUE( g.HasNode( nodes[ i ].GetId() ) );
    }
    for( int i = 10; i < 20; i++ )
        EXPECT_FALSE( g.HasNode( nodes[ i ].GetId() ) );
}
TEST( GraphInterfaceTest, AddRemoveConnectionsHandle )
{
    GraphInterface g;
    GraphNode n1, n2;
    ConnectionParams c;
    g.AddNode( n1 );
    g.AddNode( n2 );
    EXPECT_FALSE( g.AreConnected( n1, n2 ) );
    EXPECT_FALSE( g.AreConnected( n1.GetId(), n2.GetId() ) );
    g.AddConnection( n1, n2, c );
    EXPECT_TRUE( g.AreConnected( n1, n2 ) );
    EXPECT_TRUE( g.AreConnected( n1.GetId(), n2.GetId() ) );
    n1 = g.getNode( n1.GetId() );
    n2 = g.getNode( n2.GetId() );
    EXPECT_TRUE( g.AreConnected( n1, n2 ) );
    EXPECT_TRUE( g.AreConnected( n1.GetId(), n2.GetId() ) );

    EXPECT_EQ(n1.neighbors.size(), 1 );
    EXPECT_EQ(n2.neighbors.size(), 1 );

    EXPECT_EQ(n1.neighbors[ 0 ], n2.GetId() );
    EXPECT_EQ(n2.neighbors[ 0 ], n1.GetId() );
}
TEST( GraphInterfaceTest, RemoveNodeHandle )
{
    GraphInterface g;
    GraphNode n1, n2;
    ConnectionParams c;
    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddConnection( n1, n2, c );

    n1 = g.getNode( n1.GetId() );
    n2 = g.getNode( n2.GetId() );

    g.RemoveNode( n2 );
    EXPECT_FALSE( g.HasNode( n2 ) );
    EXPECT_FALSE(g.AreConnected( n1, n2 ) );
    EXPECT_EQ(g.getNode( n1.GetId() ).neighbors.size(), 0 );
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}