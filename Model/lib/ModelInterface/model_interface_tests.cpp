#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/ModelInterface/ModelInterface.h"
#include "GraphNode/GraphNode.h"
#include "GraphConnection/GraphConnection.h"
//#include "lib/ModelObserver/model_observer_tests.cpp"
using namespace Polaris;

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
    ModelSubscriber * sub = new MockSubScriber;
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
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}