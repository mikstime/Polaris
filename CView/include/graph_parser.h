#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "GraphNode/GraphNode.h"
#include "GraphConnection/GraphConnection.h"
#include "item_controller.h"
#include <unordered_map>
#include <memory>
#include "Meta/Meta.h"
#include <unordered_map>
#include <vector>

// TODO выделить интерфейс
namespace Polaris
{
    class GraphParser
    {
    public:
        explicit GraphParser() = default;
        explicit GraphParser( std::shared_ptr< ItemController > & item_controller );
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
        void EraseItems();

    private:
        std::shared_ptr< ItemController >item_cotroller_;
        // TODO обернуть в отдельный класс
        std::unordered_map< Id, GraphicItem * > items_in_controller_;

        std::unordered_map< Id, GraphicItem * >::iterator FindByPointer( const GraphicItem * const cur_item );
        bool EraseItemById( const Id cur_id );
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H