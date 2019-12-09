#ifndef MAINAPP_EDITOR_H
#define MAINAPP_EDITOR_H

#include "graphic_polygon.h"
#include <memory>
#include <QGraphicsScene>
#include <vector>

namespace Polaris
{
    class Editor
    {

    public:
        explicit Editor( QGraphicsScene * const scene );
        explicit Editor( const Editor & ) = delete;
        explicit Editor( const Editor && ) = delete;
        Editor & operator = (const Editor & ) = delete;
        Editor & operator = ( const Editor && ) = delete;
        ~Editor();

        void InitEditing( std::vector< GraphicPolygon > polygons );
        void AddPolygon( GraphicPolygon & polygon );
        void ExitEditing();

    private:
        std::unique_ptr< QGraphicsScene > scene_;
        std::vector< GraphicItem > item_;
    };
} // namespace Polaris

#endif //MAINAPP_EDITOR_H
