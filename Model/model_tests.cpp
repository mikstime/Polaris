#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/GraphInterface/GraphInterface.h"
#include <GraphNode/GraphNode.h>
#include "include/ModelInterface/ModelInterface.h"
#include <include/Search/Search.h>
#include <GraphConnection/GraphConnection.h> // ConnectionParams
using namespace Polaris;
//@TODO implement
//class MockSubScriber: public ModelSubscriber
//{
//    MOCK_METHOD(
//            void, onMetaAdded,( const Meta & meta ), ()
//    );
//    MOCK_METHOD(
//            void, onMetaChanged, ( const Meta & meta ), ()
//    );
//    MOCK_METHOD(
//            void, onMetaRemoved, ( const Meta & meta ), ()
//    );
//    MOCK_METHOD(
//            void, onConnectionAdded,( const GraphConnection & connection ), ()
//    );
//    MOCK_METHOD(
//            void, onConnectionRemoved, ( const GraphConnection & connection ), ()
//    );
//    MOCK_METHOD(
//            void, onPathFound,(
//            std::vector< Meta > & path,
//            std::vector< GraphConnection > & connections ), ()
//    );
//    MOCK_METHOD(
//            void, onNodeAdded,( const GraphNode & node ), ()
//    );
//    MOCK_METHOD(
//            void, onNodeRemoved, ( const GraphNode & node ), ()
//    );
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
class MockSubScriber: public ModelSubscriber
{
    void onMetaAdded( const Meta & meta ) override
    {
        std::cout << "onMetaAdded\n";
    }
    void onMetaChanged( const Meta & meta ) override
    {
        std::cout << "onMetaChanged\n";
    }
    void onMetaRemoved( const Meta & meta ) override
    {
        std::cout << "onMetaRemoved\n";
    }
    void onConnectionAdded( const GraphConnection & connection ) override
    {
        std::cout << "onConnectionAdded\n";
    }
    void onConnectionRemoved( const GraphConnection & connection ) override
    {
        std::cout << "onConnectionRemoved\n";
    }
    void onPathFound(
            std::vector< Meta > & path,
            std::vector< GraphConnection > & connections ) override
    {
        std::cout << "onPathFound\n";
    }
    void onNodeAdded( const GraphNode & node ) override
    {
        std::cout << "onNodeAdded\n";
    }
    void onNodeRemoved( const GraphNode & node ) override
    {
        std::cout << "onNodeRemoved\n";
    }
};
TEST( ModelInterfaceTest, HandleEvents )
{
    ModelInterface mi = ModelInterface();
    std::shared_ptr< ModelSubscriber > sub =
            std::shared_ptr< ModelSubscriber >(new MockSubScriber );
    GraphNode n1, n2; ConnectionParams c; c.cost = 4;
    GraphNode n3;

    EXPECT_TRUE( mi.Subscribe( sub ) );
    EXPECT_FALSE( mi.Subscribe( sub ) );
    EXPECT_TRUE( mi.AddNode( n1 ) );
    EXPECT_FALSE( mi.AddNode( n1 ) );
    EXPECT_TRUE( mi.AddNode( n2 ) );
    EXPECT_FALSE( mi.AddNode( n2 ) );
    EXPECT_TRUE( mi.AddConnection( n1, n2, c ) );
    EXPECT_FALSE( mi.AddConnection( n1, n2, c ) );
    EXPECT_FALSE( mi.AddConnection( n1, n3, c ) );
    EXPECT_TRUE( mi.AddNode( n3 ) );
    EXPECT_FALSE( mi.AddNode( n3 ) );
    EXPECT_TRUE( mi.AddConnection( n1, n3, c ) );
    EXPECT_FALSE( mi.AddConnection( n1, n3, c ) );
    EXPECT_TRUE( mi.RemoveConnection( n1, n3 ) );
    EXPECT_FALSE( mi.RemoveConnection( n1, n3 ) );
    EXPECT_TRUE( mi.RemoveNode( n1 ) );
    EXPECT_FALSE(mi.RemoveNode( n1 ) );
    EXPECT_FALSE( mi.AddConnection( n1, n2, c ) );
    EXPECT_FALSE( mi.RemoveConnection( n1, n2 ) );
    EXPECT_TRUE( mi.AddNode( n1 ) );
    EXPECT_FALSE( mi.AddNode( n1 ) );
    EXPECT_TRUE( mi.AddConnection( n1, n2, c ) );
    EXPECT_FALSE( mi.AddConnection( n1, n2, c ) );
}
TEST( SearchTest, SimpleSearchHandle)
{
    //*************************************************************************
    // o-o
    //*************************************************************************
    GraphInterface g;
    GraphNode n1{}, n2{};
    ConnectionParams c;
    c.cost = 4;

    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddConnection( n1.GetId(), n2.GetId(), c );

    auto res = Search::FindPath( g, n1.GetId(), n2.GetId() );

    std::string res_str;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    std::string correct = std::to_string( n1.GetId() ) + " " +
                          std::to_string( n2.GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, LineSearchHandle)
{
    //*************************************************************************
    // o-o-o-o-o-o-o-o-o-o
    //*************************************************************************
    GraphInterface g;
    std::vector< GraphNode > nodes;
    for( int i = 0; i < 10; i++ )
        nodes.emplace_back( );
    ConnectionParams c{};
    c.cost = 4;
    for( int i = 0; i < 10; i++ )
        g.AddNode( nodes[ i ] );
    for( int i = 0; i < 9; i++ )
        g.AddConnection( nodes[ i ].GetId(), nodes[ i + 1].GetId(), c );
    auto res = Search::FindPath( g, nodes[ 0 ].GetId(),
                                 nodes[ nodes.size() - 1 ].GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    for( int i = 0; i < 10; i++ )
        correct += std::to_string ( nodes[ i ].GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NotLineSearchHandle)
{
    //*************************************************************************
    // o-o-o-o-o-o-o-o-o-o
    // |___________| // all prices equal
    //*************************************************************************
    GraphInterface g;
    std::vector< GraphNode > nodes;
    for( int i = 0; i < 10; i++ )
        nodes.emplace_back( );
    ConnectionParams c{};
    c.cost = 4;
    for( int i = 0; i < 10; i++ )
        g.AddNode( nodes[ i ] );
    g.AddConnection( nodes[ 0 ].GetId(), nodes[ 6 ].GetId() , c );
    for( int i = 0; i < 9; i++ )
        g.AddConnection( nodes[ i ].GetId(), nodes[ i + 1].GetId(), c );
    auto res = Search::FindPath( g, nodes[ 0 ].GetId(),
                                 nodes[ nodes.size() - 1 ].GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    correct += std::to_string ( nodes[ 0 ].GetId() ) + " ";
    for( int i = 6; i < 10; i++ )
        correct += std::to_string ( nodes[ i ].GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NotLineSearchHandle2)
{
    //*************************************************************************
    // o-o-o-o-o-o-o-o-o-o
    // |___________| // very hich price here
    //*************************************************************************
    GraphInterface g;
    std::vector< GraphNode > nodes;
    for( int i = 0; i < 10; i++ )
        nodes.emplace_back( );
    ConnectionParams c{}, c1{};
    c.cost = 4; c1.cost = 100000;
    for( int i = 0; i < 10; i++ )
        g.AddNode( nodes[ i ] );
    g.AddConnection( nodes[ 0 ].GetId(), nodes[ 6 ].GetId() , c1 );
    for( int i = 0; i < 9; i++ )
        g.AddConnection( nodes[ i ].GetId(), nodes[ i + 1].GetId(), c );
    auto res = Search::FindPath( g, nodes[ 0 ].GetId(),
                                 nodes[ nodes.size() - 1 ].GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    for( int i = 0; i < 10; i++ )
        correct += std::to_string ( nodes[ i ].GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NotLineSearchHandle3)
{
    //*************************************************************************
    // o-o-o-o-o-o-O-o-o-o
    // |           |
    // |_________o-o
    //*************************************************************************
    GraphInterface g;
    std::vector< GraphNode > nodes;
    for( int i = 0; i < 10; i++ )
        nodes.emplace_back( );
    ConnectionParams c{}, c1{};
    c.cost = 4; c1.cost = 100000;
    for( int i = 0; i < 10; i++ )
        g.AddNode( nodes[ i ] );
    GraphNode n1{}, n2{};
    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddConnection(nodes[ 0 ].GetId() , n1.GetId(), c );
    g.AddConnection( n1.GetId(), n2.GetId(), c );
    g.AddConnection( n2.GetId(), nodes[ 6 ].GetId(), c );
    for( int i = 0; i < 9; i++ )
        g.AddConnection( nodes[ i ].GetId(), nodes[ i + 1].GetId(), c );
    auto res = Search::FindPath( g, nodes[ 0 ].GetId(),
                                 nodes[ 6 ].GetId() );

    std::string res_str, correct;
    correct = std::to_string( nodes[0].GetId() ) + " " +
              std::to_string( n1.GetId() ) + " " +
              std::to_string( n2.GetId() ) + " " +
              std::to_string( nodes[6].GetId() ) + " ";
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NotLineSearchHandle4)
{
    //*************************************************************************
    // o-o-O-o-o-o-o-o-o-o
    // |           |
    // |_________o-o
    //*************************************************************************
    GraphInterface g;
    std::vector< GraphNode > nodes;
    for( int i = 0; i < 10; i++ )
        nodes.emplace_back( );
    ConnectionParams c{}, c1{};
    c.cost = 4; c1.cost = 100000;
    for( int i = 0; i < 10; i++ )
        g.AddNode( nodes[ i ] );
    GraphNode n1{}, n2{};
    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddConnection(nodes[ 0 ].GetId() , n1.GetId(), c );
    g.AddConnection( n1.GetId(), n2.GetId(), c );
    g.AddConnection( n2.GetId(), nodes[ 6 ].GetId(), c );
    for( int i = 0; i < 9; i++ )
        g.AddConnection( nodes[ i ].GetId(), nodes[ i + 1].GetId(), c );
    auto res = Search::FindPath( g, nodes[ 0 ].GetId(),
                                 nodes[ 2 ].GetId() );

    std::string res_str, correct;
    for( int i = 0; i < 3; i++ )
        correct += std::to_string ( nodes[ i ].GetId() ) + " ";
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NotLineSearchHandle5)
{
    //*************************************************************************
    // o-o-o-o-o-O-o-o-o-o
    // |           |
    // |_________o-o
    //*************************************************************************
    GraphInterface g;
    std::vector< GraphNode > nodes;
    for( int i = 0; i < 10; i++ )
        nodes.emplace_back( );
    ConnectionParams c{}, c1{};
    c.cost = 4; c1.cost = 100000;
    for( int i = 0; i < 10; i++ )
        g.AddNode( nodes[ i ] );
    GraphNode n1{}, n2{};
    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddConnection(nodes[ 0 ].GetId() , n1.GetId(), c );
    g.AddConnection( n1.GetId(), n2.GetId(), c );
    g.AddConnection( n2.GetId(), nodes[ 6 ].GetId(), c );
    for( int i = 0; i < 9; i++ )
        g.AddConnection( nodes[ i ].GetId(), nodes[ i + 1].GetId(), c );
    auto res = Search::FindPath( g, nodes[ 0 ].GetId(),
                                 nodes[ 5 ].GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    correct = std::to_string( nodes[0].GetId() ) + " " +
              std::to_string( n1.GetId() ) + " " +
              std::to_string( n2.GetId() ) + " " +
              std::to_string( nodes[6].GetId() ) + " " +
              std::to_string( nodes[5].GetId() ) + " ";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NoPathHandle )
{
    //*************************************************************************
    // o o
    //*************************************************************************
    GraphInterface g;
    GraphNode n1{}, n2{};
    g.AddNode( n1 );
    g.AddNode( n2 );
    auto res = Search::FindPath( g, n1.GetId(), n2.GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    correct = "";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, NoPathHandle2 )
{
    //*************************************************************************
    // o-o o
    //*************************************************************************
    GraphInterface g;
    GraphNode n1{}, n2{}, n3{};
    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddNode( n3 );
    ConnectionParams c;
    c.cost = 4;
    g.AddConnection( n1, n2, c );
    auto res = Search::FindPath( g, n1.GetId(), n3.GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";
    correct = "";
    EXPECT_EQ( res_str, correct );
}
TEST( SearchTest, SQPATH )
{
    //Test failed in demo.
    GraphInterface g;
    GraphNode n1{}, n2{}, n3{}, n4{};
    g.AddNode( n1 );
    g.AddNode( n2 );
    g.AddNode( n3 );
    g.AddNode( n4 );
    ConnectionParams c12, c23, c13, c34;
    c12.cost = 4;
    c23.cost = 5;
    c13.cost = 5;
    c34.cost = 3;
    g.AddConnection( n1, n2, c12 );
    g.AddConnection( n2, n3, c23 );
    g.AddConnection( n1, n3, c13 );
    g.AddConnection( n3, n4, c34 );
    auto res = Search::FindPath( g, n1.GetId(), n4.GetId() );

    std::string res_str, correct;
    for( auto & e: res)
        res_str += std::to_string( e.GetId() ) + " ";

    correct = std::to_string( n1.GetId() ) + " " +
              std::to_string( n3.GetId() ) + " " +
              std::to_string( n4.GetId() ) + " ";

    EXPECT_EQ( res_str, correct );
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}