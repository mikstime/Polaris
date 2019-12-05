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
    EXPECT_EQ( res_str, "1 2 ");
}
TEST( SearchTest, LineSearchHandle)
{
    //@TODO implement test
//    GraphInterface g;
//    GraphNode n1{}, n2{};
//    std::vector< GraphNode > nodes;
//    for( int i = 0; i < 10; i++ )
//    ConnectionParams c{};
//    c.cost = 4;
//
//    g.AddNode( n1 );
//    g.AddNode( n2 );
//    g.AddConnection( n1.GetId(), n2.GetId(), c );
//
//    auto res = Search::FindPath( g, n1.GetId(), n2.GetId() );
//
//    std::string res_str;
//    for( auto & e: res)
//        res_str += std::to_string( e.GetId() ) + " ";
//    EXPECT_EQ( res_str, "1 2 ");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}