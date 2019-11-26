#include "include/item_controller.h"

using Polaris::ItemController;

ItemController::ItemController( const QRect & scene_rect, QObject * parent )
: QGraphicsScene( scene_rect, parent )
{

}

size_t ItemController::GetCurrentNode() const
{
    return current_node_;
}

size_t ItemController::GetPreviousNode() const
{
    return previous_node_;
}

QPointF ItemController::GetMarkDownPos() const
{
    return mark_down_.isVisible() ? mark_down_.pos() : QPointF( -1, -1 );
}

void ItemController::mousePressEvent(QGraphicsSceneMouseEvent *mouse_event)
{

}

void ItemController::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse_event)
{

}