#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/GraphInterface/GraphInterface.h"
#include <include/Graph/Graph.h>
#include <include/GraphNode/GraphNode.h>
#include <include/GraphConnection/GraphConnection.h> // ConnectionParams
using namespace Polaris;

class MockGraphInterface: public GraphInterface
{
    using Id = size_t;
public:
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

    MockGraphInterface graphInterface = MockGraphInterface();

    GraphNode testNode1 = GraphNode();
    GraphNode testNode2 = GraphNode();

    EXPECT_CALL(graphInterface, AddNode( testNode1 )).Times(AtLeast(1));
    EXPECT_CALL(graphInterface, AddNode( testNode2 )).Times(AtLeast(1));

    graphInterface.AddNode(testNode1);
    graphInterface.AddNode(testNode2);
    // No nodes must be connected
    ASSERT_FALSE(graphInterface.AreConnected(testNode1, testNode2));
    ASSERT_FALSE( graphInterface.AreConnected( testNode1, testNode2 ));
    ASSERT_FALSE( graphInterface.AreConnected(
            testNode1.getId(), testNode2.getId() ));
    // Add connection between nodes
    graphInterface.AddConnection(testNode1, testNode2);
    // Only testNode1 and testNode2 are expected to be connected
    ASSERT_TRUE( graphInterface.AreConnected(testNode1, testNode2));
    ASSERT_TRUE(graphInterface.AreConnected(
                    testNode1.getId(), testNode2.getId()));
    ASSERT_FALSE( graphInterface.AreConnected( testNode1, testNode2 ));
    ASSERT_FALSE( graphInterface.AreConnected(
            testNode1.getId(), testNode2.getId() ));
    // set connectionParams
    ConnectionParams connectionParams = ConnectionParams();
    connectionParams.cost = 4;
    graphInterface.SetConnectionParams(testNode1, testNode2, connectionParams);
    ASSERT_EQ(graphInterface.getConnection(testNode1, testNode2).cost,
            connectionParams.cost);
    graphInterface.RemoveConnection(testNode1, testNode2);
    ASSERT_FALSE(graphInterface.AreConnected(testNode1, testNode2));
    graphInterface.AddConnection(testNode1, testNode2);
    ASSERT_TRUE(graphInterface.AreConnected(testNode1, testNode2));
    graphInterface.RemoveNode(testNode1);
    ASSERT_FALSE(graphInterface.AreConnected(testNode1, testNode2));
    ASSERT_FALSE(graphInterface.HasNode(testNode1));
    ASSERT_FALSE(graphInterface.AreConnected(testNode1, testNode2));

}
int main() {

}