#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "item_controller.h"
#include <memory>
#include <QGraphicsScene>
// TODO временный путь до заголовочных файлов
#include "../Model/include/Meta/Meta.h"
#include "../Model/include/GraphConnection/GraphConnection.h"


namespace Polaris
{
    class GraphParser
    {
    public:
        explicit GraphParser( ItemController * item_controller );
        GraphParser( const GraphParser & ) = delete;
        GraphParser( const GraphParser && ) = delete;
        GraphParser & operator = ( const GraphParser & ) = delete;
        GraphParser & operator = ( const GraphParser && ) = delete;

        void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph );
        void OnPathFound( const std::vector< const GraphNode > & nodes,
                const std::vector< const GraphConnection > & connections );
        void OnMetaChanged( const Meta & meta );
        void OnRoomAdded(const Meta & meta );
        void OnRoomRemoved(const Meta & meta );
        void OnConnectionAdded( const GraphConnection & connection );
        void OnConnectionRemoved( const GraphConnection & connection );

    private:
        ItemController * item_cotroller_;

    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H
