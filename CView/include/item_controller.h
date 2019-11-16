#ifndef MAINAPP_ITEM_CONTROLLER_H
#define MAINAPP_ITEM_CONTROLLER_H

#include <QGraphicsScene>

namespace Polaris
{
    class ItemController : public QGraphicsScene
    {
    public:
        explicit ItemController( const QRectF & sceneRect, QObject * parent = nullptr );
        ItemController( const ItemController & ) = delete;
        ItemController( const ItemController && ) = delete;
        ItemController & operator = ( const ItemController & ) = delete;
        ItemController & operator = ( const ItemController && ) = delete;

        size_t GetCurrentNode() const;
        size_t GetPreviousNode() const;
        void mousePressEvent( QMouseEvent );
        void mouseReleaseEvent( QMouseEvent );

    private:
        size_t current_node_;
        size_t previous_node_;
    };
} // namespace Polaris

#endif //MAINAPP_ITEM_CONTROLLER_H
