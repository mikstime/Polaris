#include "include/item_controller.h"

using Polaris::ItemController;

ItemController::ItemController( const QRectF & scene_rect, QObject * parent )
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

void ItemController::mousePressEvent(QGraphicsSceneMouseEvent *mouse_event)
{

}

void ItemController::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse_event)
{

}