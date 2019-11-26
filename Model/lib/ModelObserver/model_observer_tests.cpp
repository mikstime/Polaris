#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/Meta/Meta.h"
#include "include/ModelObserver/ModelObserver.h"
#include "include/GraphNode/GraphNode.h"
#include "include/GraphConnection/GraphConnection.h"
#include "include/ModelSubscriber/ModelSubscriber.h"
using namespace Polaris;
class MockModelObserver: public ModelObserver
{
public:
    MOCK_METHOD(
    void, Subscribe,( const ModelSubscriber & subscriber ), ()
    );
    MOCK_METHOD(
    void, unSubscribe,( const ModelSubscriber & subscriber ), ()
    );
    MOCK_METHOD(
    void, MetaChanged,( const Meta & newMeta ), ()
    );
    MOCK_METHOD(
    void, ConnectionAdded,( const GraphNode & firstNode,
                          const GraphNode & lastNode ), ()
    );
    MOCK_METHOD(
    void, ConnectionRemoved,( const GraphNode & firstNode,
                            const GraphNode & lastNode ), ()
    );
    MOCK_METHOD(
    void, NodeAdded,( const GraphNode & node ), ());
    MOCK_METHOD(
    void, NodeRemoved,( const GraphNode & node ), ());
};