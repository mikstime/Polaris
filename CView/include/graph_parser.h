#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "item_controller.h"
#include <memory>
#include <QGraphicsScene>

struct Meta{};
struct Graph{};

namespace Polaris
{
    class GraphParser
    {
    public:
        explicit GraphParser( std::shared_ptr< ItemController > item_controller );
        GraphParser( const GraphParser & ) = delete;
        GraphParser( const GraphParser && ) = delete;
        GraphParser & operator = ( const GraphParser & ) = delete;
        GraphParser & operator = ( const GraphParser && ) = delete;

        void BuildItems( const Meta & meta, const Graph & graph );
        void RefreshItems( const Meta & meta, const Graph & graph, QVector< int > change_list);
        void DrawThePath( QVector< size_t > path );

    private:
        std::shared_ptr< ItemController > item_cotroller_;

    };
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H
