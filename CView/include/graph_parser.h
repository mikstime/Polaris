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
        void RefreshItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph,
                           std::vector< size_t > change_list);
        void DrawThePath( std::vector< size_t > path );

    private:
        ItemController * item_cotroller_;

    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H
