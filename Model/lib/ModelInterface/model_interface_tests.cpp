#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/ModelInterface/ModelInterface.h"
#include "include/GraphNode/GraphNode.h"
#include "include/GraphConnection/GraphConnection.h"
#include "lib/ModelObserver/model_observer_tests.cpp"
using namespace Polaris;

class MockModelInterface: public ModelInterface
{
    using Id = size_t;
public:

    MockModelInterface( const ModelObserver &){};
    MOCK_METHOD(void, AddNode, ( const GraphNode &), ());
    MOCK_METHOD(void, AddNode, (Id), ());
    MOCK_METHOD(void, AddConnection, ( const GraphNode &,
            const GraphNode & ), ());
    MOCK_METHOD(void, AddConnection, ( Id, Id ), ());
    MOCK_METHOD(void, RemoveNode, ( const GraphNode & ), ());
    MOCK_METHOD(void, RemoveNode, ( Id ), ());
    MOCK_METHOD(bool, HasNode, ( Id ), ());
    MOCK_METHOD(bool, HasNode, ( const GraphNode & ), ());
    MOCK_METHOD(bool, AreConnected, ( Id, Id ), ());
    MOCK_METHOD(bool, AreConnected, ( const GraphNode &,
            const GraphNode & ), ());
};
TEST( GraphInterfaceTest, AddMethodsHandle )
{
    using ::testing::AtLeast;
    MockModelObserver mo = MockModelObserver();
    MockModelInterface mi = MockModelInterface(mo);
    using ::testing::AtLeast;

    GraphNode testNode1 = GraphNode();
    GraphNode testNode2 = GraphNode();

    EXPECT_CALL(mi, AddNode( testNode1 )).Times(AtLeast(1));
    EXPECT_CALL(mi, AddNode( testNode2 )).Times(AtLeast(1));
    //@TODO remove second arg from header.
    EXPECT_CALL(mo, MetaChanged( Meta() )).Times(3);
    EXPECT_CALL(mo, NodeAdded( testNode1)).Times(AtLeast(1));
    EXPECT_CALL(mo, MetaChanged( testNode2)).Times(AtLeast(1));
    EXPECT_CALL(mo, ConnectionAdded( testNode1, testNode2)).Times(AtLeast(2));
    EXPECT_CALL(mo, ConnectionRemoved( testNode1, testNode2)).Times(AtLeast(2));

    mi.AddNode(testNode1);
    mi.AddNode(testNode2);
    // No nodes must be connected
    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
    ASSERT_FALSE( mi.AreConnected( testNode1, testNode2 ));
    ASSERT_FALSE( mi.AreConnected(
            testNode1.getId(), testNode2.getId() ));
    // Add connection between nodes
    mi.AddConnection(testNode1, testNode2);
    // Only testNode1 and testNode2 are expected to be connected
    ASSERT_TRUE( mi.AreConnected(testNode1, testNode2));
    ASSERT_TRUE(mi.AreConnected(
            testNode1.getId(), testNode2.getId()));
    ASSERT_FALSE( mi.AreConnected( testNode1, testNode2 ));
    ASSERT_FALSE( mi.AreConnected(
            testNode1.getId(), testNode2.getId() ));

    mi.RemoveConnection(testNode1, testNode2);
    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
    mi.AddConnection(testNode1, testNode2);
    ASSERT_TRUE(mi.AreConnected(testNode1, testNode2));
    mi.RemoveNode(testNode1);
    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
    ASSERT_FALSE(mi.HasNode(testNode1));
    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
}
int main() {

}