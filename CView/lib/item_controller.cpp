#include "include/item_controller.h"
#include "include/graphic_item.h"
#include "include/graphic_room.h"
#include <string>
#include <QGraphicsSceneMouseEvent>

using std::string_literals::operator""s;
using Polaris::GraphicRoom;
using Polaris::ItemController;

ItemController::ItemController( const QRect & scene_rect, QObject * parent )
: QGraphicsScene( scene_rect, parent ),
current_node_( nullptr ),
previous_node_( nullptr )
{

}

size_t ItemController::GetCurrentNode() const
{
    return current_node_ != nullptr ? current_node_->GetId() : 0;
}

size_t ItemController::GetPreviousNode() const
{
    return previous_node_ != nullptr ? previous_node_->GetId() : 0;
}

QPointF ItemController::GetMarkDownPos() const
{
    return mark_down_.isVisible() ? mark_down_.pos() : QPointF( -1, -1 );
}

void ItemController::mousePressEvent( QGraphicsSceneMouseEvent * mouse_event )
{
    // выбранный итем
    QGraphicsItem * cur_item = this->itemAt( mouse_event->pos(), QTransform() );
    GraphicItem * cast_item = qgraphicsitem_cast< GraphicItem * >( cur_item );

    if( mouse_event->button() == Qt::MouseButton::LeftButton ) // левая кнопка мыши
    {
        if( cast_item != nullptr && ( cast_item->GetRole() == "room"s ||
                                      cast_item->GetRole() == "hall"s ||
                                      cast_item->GetRole() == "stair"s ) ) // выбор комнаты
        {
            SelectCurrentNode( cast_item );
            ResetPreviousNode();
            mark_down_.hide();
        }
        else if( cast_item != nullptr && cast_item->GetRole() == "mark"s ) // выбор марки
        {
            mark_down_.hide();
        }
        else if( cast_item == nullptr ) // клик по постому пространству экрана
        {
            ResetPreviousNode();
            // TODO переместить марку
            mark_down_.show();
        }
    }
    else if ( mouse_event->button() == Qt::MouseButton::RightButton && cur_item == nullptr ) // правая кнопка
    {
        ResetCurrentNode();
        ResetPreviousNode();
    }
}

void ItemController::mouseReleaseEvent( QGraphicsSceneMouseEvent * mouse_event )
{
    QGraphicsItem * cur_item = this->itemAt( mouse_event->pos(), QTransform() );
    GraphicItem * cast_item = qgraphicsitem_cast< GraphicItem * >( cur_item );

    if( mouse_event->button() == Qt::MouseButton::LeftButton )
    {
        if( cast_item != nullptr && ( cast_item->GetRole() == "room"s ||
                                      cast_item->GetRole() == "hall"s ||
                                      cast_item->GetRole() == "stair"s ) ) // соединить ноды
        {
            size_t tmp_node = cast_item->GetId();
            if( tmp_node != current_node_->GetId() ) // если соединение не с самим собой
            {
                SelectPreviousNode( cast_item );
                mark_down_.hide();
            }
        }
        else // сбросить соединение
        {
            ResetCurrentNode();
            ResetPreviousNode();
            mark_down_.hide();
        }
    }
    // обновить сцену
    this->update();
}

void ItemController::SelectCurrentNode( GraphicItem * const new_current )
{
    if( current_node_ != nullptr )
    {
        current_node_->ResetSelection();
    }

    current_node_ = new_current;
    current_node_->SetSelection();
}

void ItemController::SelectPreviousNode( GraphicItem * const new_current )
{
    if( previous_node_ != nullptr )
    {
        previous_node_->ResetSelection();
    }

    previous_node_ = new_current;
    previous_node_->SetSelection();
}

void ItemController::ResetCurrentNode()
{
    if( current_node_ != nullptr )
    {
        current_node_->ResetSelection();
        current_node_ = nullptr;
    }
}

void ItemController::ResetPreviousNode()
{
    if( previous_node_ != nullptr )
    {
        previous_node_->ResetSelection();
        previous_node_ = nullptr;
    }
}