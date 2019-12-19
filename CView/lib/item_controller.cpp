#include "include/item_controller.h"
#include <string>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

using std::string_literals::operator""s;
using Polaris::GraphicRoom;
using Polaris::ItemController;

ItemController::ItemController( const QRect & scene_rect, std::shared_ptr< ItemCollaction > items_in_controller,
                                QObject * parent )
: QGraphicsScene( scene_rect, parent ),
editor_( std::make_unique< Editor >( this ) ),
items_in_controller_( items_in_controller ),
current_node_( nullptr ),
previous_node_( nullptr ),
path_drawn_( false ),
is_edit_( false )
{
    this->addItem( & mark_down_ );
}

ItemController::~ItemController()
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

    return editor_->GetPos();
}

QPolygonF ItemController::GetNewForm() const
{
    if( is_edit_ )
    {
        return editor_->GetNewForm();
    }
    else
    {
        return QPolygonF();
    }
}

void ItemController::SetCurPath( std::vector< GraphicItem * > & cur_path )
{
    cur_path_ = std::move( cur_path );

    for( const auto & k : cur_path_ )
    {
        k->SetColor( Qt::red );
    }

    this->update();
    path_drawn_ = true;
}

void ItemController::mousePressEvent( QGraphicsSceneMouseEvent * mouse_event )
{
    // выбранный итем
    QPointF cur_pos = mouse_event->scenePos();
    QGraphicsItem * cur_item = this->itemAt( cur_pos, QTransform() );
    GraphicItem * cast_item = static_cast< GraphicItem * >( cur_item );

    if( path_drawn_ )
        ResetPath();

    if( is_edit_ && mouse_event->button() == Qt::MouseButton::LeftButton )
    //TODO еренести в хэндлклик
    {
        if( cast_item != nullptr && cast_item->GetRole() != Polaris::Role::CONNECTION )
        {
            editor_->AddConnections( cast_item->GetSize(), cast_item->pos() );
        }
        else if( cast_item != nullptr )
        {
            if( mouse_event->modifiers() & Qt::ControlModifier )
            {
                editor_->SelectConnection( cast_item );
            }
            else
            {
                editor_->EraseItem( cast_item );
            }
        } else if( cast_item == nullptr )
        {
            editor_->AddConnection( cur_pos );
        }
    }
    else if( mouse_event->button() == Qt::MouseButton::LeftButton ) // левая кнопка мыши
    {
        if( cast_item != nullptr && cast_item->GetRole() != Polaris::Role::CONNECTION ) // выбор комнаты
        {
            if( mouse_event->modifiers() & Qt::ControlModifier )
            {
                RoomPressedLeftCtrl(cast_item, cur_pos);
            }
            else
            {
                RoomPressedLeft(cast_item, cur_pos);
            }
        }
        else if( cast_item == nullptr ) // клик по постому пространству экрана
        {
            if( mouse_event->modifiers() & Qt::ControlModifier )
            {
                EmptyPressedLeftCtrl(cast_item, cur_pos);
            }
            else
            {
                EmptyPressedLeft(cur_pos);
            }
        }
    }
    else if ( mouse_event->button() == Qt::MouseButton::RightButton && cur_item == nullptr ) // правая кнопка
    {
        EmptyPressedRight( cur_pos );
    }
    this->update();
}

void ItemController::mouseReleaseEvent( QGraphicsSceneMouseEvent * mouse_event )
{
//    QPointF cur_pos = mouse_event->scenePos();
//    QGraphicsItem * cur_item = this->itemAt( cur_pos, QTransform() );
//    GraphicItem * cast_item = static_cast< GraphicItem * >( cur_item );
//
//    // TODO разбить на фукнции по событиям разных кликов
//    if( mouse_event->button() == Qt::MouseButton::LeftButton )
//    {
//        if( cast_item != nullptr && ( cast_item->GetRole() == Polaris::Role::ROOM ||
//                                      cast_item->GetRole() == Polaris::Role::HALL ||
//                                      cast_item->GetRole() == Polaris::Role::STAIR ) ) // соединить ноды
//        {
//
//        }
//        else // сбросить соединение
//        {
//
//        }
//    }
//    this->update();
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

bool ItemController::ChangeMode( bool edit )
{
//    if( is_edit_ )
//        editor_->FinishEditing();
    qInfo() << "Editing: " << is_edit_;
    is_edit_ = !is_edit_;
    editor_->FinishEditing();
    qInfo() << "Editing: " << is_edit_;
    return  is_edit_;
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
//        previous_node_ = new_current;
    }

    if( current_node_ != nullptr )
    {
        previous_node_ = new_current;
        previous_node_->SetSelection();
    }
    else
    {
        current_node_ = new_current;
        current_node_->SetSelection();
    }

}

void ItemController::ResetPath()
{
    for( auto & k : cur_path_ )
    {
        k->SetDefaultColor();
    }

    cur_path_.erase( cur_path_.begin(), cur_path_.end() );
    path_drawn_ =false;
}

void ItemController::RoomPressedLeft(GraphicItem * const cur_item, const QPointF & cur_pos )
{
    SelectCurrentNode( cur_item );
    ResetPreviousNode();
//    mark_down_.hide();
}

void ItemController::EmptyPressedLeft(const QPointF & cur_pos )
{
    ResetPreviousNode();
    ResetCurrentNode();
//    mark_down_.setPos( cur_pos );
//    mark_down_.show();
}

void ItemController::RoomPressedLeftCtrl(GraphicItem * const cur_item, const QPointF & cur_pos )
{
//    mark_down_.hide();
    SelectPreviousNode( cur_item );
}

void ItemController::EmptyPressedLeftCtrl(GraphicItem * const cur_item, const QPointF & cur_pos )
{
    ResetPreviousNode();
//    mark_down_.setPos( cur_pos );
//    mark_down_.show();
}

void ItemController::EmptyPressedRight(const QPointF & cur_pos )
{
    ResetCurrentNode();
    ResetPreviousNode();
}

void ItemController::RoomReleaseLeft(GraphicItem * const cur_item, const QPointF & cur_pos )
{
    if( cur_item != current_node_ ) // если соединение не с самим собой
    {
        SelectPreviousNode( cur_item );
//        mark_down_.hide();
    }
}

void ItemController::EmptyReleaseLeft(const QPointF & cur_pos )
{

}

void ItemController::RoomReleaseRight(GraphicItem * const cur_item, const QPointF & cur_pos )
{
    if( cur_item != current_node_ ) // если соединение не с самим собой
    {
        SelectPreviousNode( cur_item );
//        mark_down_.hide();
    }
}

void ItemController::EmptyReleaseRight(const QPointF & cur_pos )
{

}
