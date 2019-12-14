#include <gtest/gtest.h>
#include <GraphNode/GraphNode.h>
#include "GraphConnection/GraphConnection.h"
using namespace Polaris;
TEST( GraphConnectionTest, copy_test )
{
    GraphConnection c1, c2( c1 );
    EXPECT_EQ(c1.GetId(), c2.GetId() );
    GraphConnection c3( 4 ), c4 = c3;
    EXPECT_EQ(c3.GetId(), c4.GetId() );
    GraphConnection c5( 1, 2, 3 ), c6( c5 );
    EXPECT_EQ( c5.GetId(), c6.GetId() );
    EXPECT_EQ( c5.from, c6.from );
    EXPECT_EQ( c5.to, c6.to );
    EXPECT_EQ( c5.cost, c6.cost );
}
TEST( GraphElementTest, copy_test )
{
    GraphElement e1, e2( e1 );
    EXPECT_EQ(e1.GetId(), e2.GetId() );
    GraphElement e3( 4 ), e4 = e3;
    EXPECT_EQ(e3.GetId(), e4.GetId() );
}
TEST( GraphNodeTest, copy_test )
{
    GraphNode n1, n2( n1 );
    EXPECT_EQ(n1.GetId(), n2.GetId() );
    GraphNode n3( 4 ), n4 = n3;
    EXPECT_EQ(n3.GetId(), n4.GetId() );
    GraphNode n5;
    n5.neighbors.push_back( n1.GetId() );
    GraphNode n6( n5 );
    EXPECT_EQ( n5.GetId(), n6.GetId() );
    EXPECT_EQ( n5.neighbors, n6.neighbors );
    n6.neighbors.erase( n6.neighbors.begin() );
    EXPECT_EQ( n5, n6 ); // Not an error
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}