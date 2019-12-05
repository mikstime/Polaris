#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "graphic_item.h"
#include "GraphNode/GraphNode.h"
#include "GraphConnection/GraphConnection.h"
#include "item_controller.h"
#include <unordered_map>
#include <memory>
// TODO временный путь до заголовочных файлов
#include "Meta/Meta.h"



namespace Polaris
{
    class GraphParser
    {
    public:
        explicit GraphParser( std::shared_ptr< ItemController > & item_controller );
        ~GraphParser();
        GraphParser( const GraphParser & ) = delete;
        GraphParser( const GraphParser && ) = delete;
        GraphParser & operator = ( const GraphParser & ) = delete;
        GraphParser & operator = ( const GraphParser && ) = delete;

        void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph );
        void OnPathFound( const std::vector< const GraphNode > & nodes,
                          const std::vector< const GraphConnection > & connections );
        void OnRoomChanged( const Meta & meta );
        void OnRoomAdded( const Meta & meta );
        void OnRoomRemoved( const Meta & meta );
        void OnConnectionAdded( const GraphConnection & connection );
        void OnConnectionRemoved( const GraphConnection & connection );

    private:
        std::shared_ptr< ItemController >item_cotroller_;
        std::unordered_map< Id, GraphicItem * > items_in_controller_;

        std::unordered_map< Id, GraphicItem * >::iterator FindByPointer( const GraphicItem * const cur_item );
        bool EraseItemById( const Id cur_id );
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H