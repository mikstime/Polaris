#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "item_controller.h"
#include "item_collaction.h"
#include "graphic_connection.h"
#include <unordered_map>
#include <memory>
#include <unordered_map>
#include <vector>

namespace Polaris
{
    class GraphParser
    {
    public:
        explicit GraphParser() = default;
        explicit GraphParser( std::shared_ptr< ItemController > & item_controller,
                              std::shared_ptr< ItemCollaction > items_in_controller );
        virtual ~GraphParser();
        GraphParser( const GraphParser & ) = delete;
        GraphParser( const GraphParser && ) = delete;
        GraphParser & operator = ( const GraphParser & ) = delete;
        GraphParser & operator = ( const GraphParser && ) = delete;
        virtual void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph );
        virtual void DrawThePath( const std::vector< Meta > & nodes,
                                       const std::vector< GraphConnection > & connections );
        virtual void OnRoomChanged( const Meta & meta );
        virtual void OnRoomAdded( const Meta & meta );
        virtual void OnRoomRemoved( const Meta & meta );
        virtual void OnConnectionAdded( const GraphConnection & connection );
        virtual void OnConnectionRemoved( const GraphConnection & connection );

    private:
        std::shared_ptr< ItemController >item_controller_;
        std::shared_ptr< ItemCollaction > items_in_controller_;

        bool EraseItem( const Id id );

    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H