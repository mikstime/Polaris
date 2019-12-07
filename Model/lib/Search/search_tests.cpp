#include <gtest/gtest.h>
#include <iostream>
#include "include/GraphInterface/GraphInterface.h"
#include <include/Graph/Graph.h>
#include <GraphNode/GraphNode.h>
#include <include/Search/Search.h>
#include <GraphConnection/GraphConnection.h> // ConnectionParams
using namespace Polaris;

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
//int main(int argc, char **argv) {
//    testing::InitGoogleTest();
//    return RUN_ALL_TESTS();
//}