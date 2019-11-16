#ifndef MAINAPP_ITEM_CONTROLLER_H
#define MAINAPP_ITEM_CONTROLLER_H

#include <QGraphicsScene>
#include <QMouseEvent>

namespace Polaris
{
    class ItemController : public QGraphicsScene
    {
    public:
        explicit ItemController( const QRectF & scene_rect, QObject * parent = nullptr );
        ItemController( const ItemController & ) = delete;
        ItemController( const ItemController && ) = delete;
        ItemController & operator = ( const ItemController & ) = delete;
        ItemController & operator = ( const ItemController && ) = delete;

        size_t GetCurrentNode() const;
        size_t GetPreviousNode() const;
        void mousePressEvent( QGraphicsSceneMouseEvent * mouse_event ) override;
        void mouseReleaseEvent( QGraphicsSceneMouseEvent * mouse_event ) override;

    private:
        size_t current_node_;
        size_t previous_node_;
    };
} // namespace Polaris

#endif //MAINAPP_ITEM_CONTROLLER_H
