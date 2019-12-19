#ifndef MAINAPP_EDITOR_H
#define MAINAPP_EDITOR_H

#include "graphic_connection.h"
#include <memory>
#include <QGraphicsScene>
#include <list>
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

        void AddConnections( const QPolygonF & polygon );
        void AddConnection( QPointF & pos );
        void SelectConnection( GraphicItem * const item );
        void EraseItem( GraphicItem * const item );
        void FinishEditing();
        QPolygonF GetNewForm() const;
        QPointF GetPos() const;

    private:
        std::unique_ptr< QGraphicsScene > scene_;
        std::list< GraphicItem * > connections_;
        std::vector< QPointF > selected_;
    };
} // namespace Polaris

#endif //MAINAPP_EDITOR_H
