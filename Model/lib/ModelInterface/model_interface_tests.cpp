#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/ModelInterface/ModelInterface.h"
#include "GraphNode/GraphNode.h"
#include "GraphConnection/GraphConnection.h"
//#include "lib/ModelObserver/model_observer_tests.cpp"
using namespace Polaris;

//class MockModelInterface: public ModelInterface
//{
//    using Id = size_t;
//public:
//
//    explicit MockModelInterface( const ModelObserver &){};
//    MOCK_METHOD(void, AddNode, ( const GraphNode &), ());
//    MOCK_METHOD(void, AddNode, (const Id &), ());
//    MOCK_METHOD(void, AddConnection, ( const GraphNode &,
//            const GraphNode & ), ());
//    MOCK_METHOD(void, AddConnection, ( const Id &, const Id & ), ());
//    MOCK_METHOD(void, RemoveNode, ( const GraphNode & ), ());
//    MOCK_METHOD(void, RemoveNode, ( const Id & ), ());
//    MOCK_METHOD(bool, HasNode, ( const Id & ), ());
//    MOCK_METHOD(bool, HasNode, ( const GraphNode & ), ());
//    MOCK_METHOD(bool, AreConnected, ( const Id &, const Id & ), ());
//    MOCK_METHOD(bool, AreConnected, ( const GraphNode &,
//            const GraphNode & ), ());
//};
TEST( ModelInterfaceTest, AddMethodsHandle )
{
    using ::testing::AtLeast;
    ModelObserver mo = ModelObserver();
    ModelInterface mi = ModelInterface();
    using ::testing::AtLeast;

    GraphNode testNode1 = GraphNode();
    GraphNode testNode2 = GraphNode();

//    EXPECT_CALL(mo, NodeAdded( testNode1 )).Times(AtLeast(1));
//    EXPECT_CALL(mo, NodeAdded( testNode2 )).Times(AtLeast(1));
//    EXPECT_CALL(mo, ConnectionAdded( testNode1, testNode1 ))
//    .Times(AtLeast(2));
//    EXPECT_CALL(mo, ConnectionRemoved( testNode1, testNode2 ))
//    .Times(AtLeast(2));

    mi.AddNode(testNode1);
    mi.AddNode(testNode2);
    // No nodes must be connected
//    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
//    ASSERT_FALSE( mi.AreConnected( testNode1, testNode2 ));
//    ASSERT_FALSE( mi.AreConnected(
//            testNode1.GetId(), testNode2.GetId() ));
    // Add connection between nodes
    ConnectionParams p;
    mi.AddConnection(testNode1, testNode2, p);
    // Only testNode1 and testNode2 are expected to be connected
//    ASSERT_TRUE( mi.AreConnected(testNode1, testNode2));
//    ASSERT_TRUE(mi.AreConnected(
//            testNode1.GetId(), testNode2.GetId()));
//    ASSERT_FALSE( mi.AreConnected( testNode1, testNode2 ));
//    ASSERT_FALSE( mi.AreConnected(
//            testNode1.GetId(), testNode2.GetId() ));

//    mi.RemoveConnection(testNode1, testNode2);
//    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
//    mi.AddConnection(testNode1, testNode2);
//    ASSERT_TRUE(mi.AreConnected(testNode1, testNode2));
//    mi.RemoveNode(testNode1);
//    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
//    ASSERT_FALSE(mi.HasNode(testNode1));
//    ASSERT_FALSE(mi.AreConnected(testNode1, testNode2));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}