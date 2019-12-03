#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "graphic_item.h"
#include "item_controller.h"
#include <memory>
#include <map>
// TODO временный путь до заголовочных файлов
#include "../Utils/Meta/Meta.h"
#include "../Utils/GraphNode/GraphNode.h"
#include "../Utils/GraphConnection/GraphConnection.h"


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
        void OnRoomChanged(const Meta & meta );
        void OnRoomAdded(const Meta & meta );
        void OnRoomRemoved(const Meta & meta );
        void OnConnectionAdded( const GraphConnection & connection );
        void OnConnectionRemoved( const GraphConnection & connection );

    private:
        std::shared_ptr< ItemController >item_cotroller_;
        std::vector< GraphicItem * > items_in_controller_;

        void SortItems();
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H
