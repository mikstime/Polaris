#include "include/ModelSubscriber/ModelSubscriber.h"
#include <gmock/gmock.h>

class MockSubScriber: public ModelSubscriber
{
    MOCK_METHOD(
            void, onMetaAdded,( const Meta & meta ), ()
    );
    MOCK_METHOD(
            void, onMetaChanged, ( const Meta & meta ), ()
    );
    MOCK_METHOD(
            void, onMetaRemoved, ( const Meta & meta ), ()
    );
    MOCK_METHOD(
            void, onConnectionAdded,( const GraphConnection & connection ), ()
    );
    MOCK_METHOD(
            void, onConnectionRemoved, ( const GraphConnection & connection ), ()
    );
    MOCK_METHOD(
            void, onPathFound,(
            std::vector< Meta > & path,
                    std::vector< GraphConnection > & connections ), ()
    );
    MOCK_METHOD(
            void, onNodeAdded,( const GraphNode & node ), ()
    );
    MOCK_METHOD(
            void, onNodeRemoved, ( const GraphNode & node ), ()
    );
};