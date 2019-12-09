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
path_drawn_( false )
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
    return mark_down_.isVisible() ? mark_down_.pos() : QPointF( -1, -1 );
}

void ItemController::SetCurPath( std::vector< GraphicItem * > & cur_path )
{
    cur_path_ = std::move( cur_path );

    for( const auto & k : cur_path_ )
    {
        k->SetColor( Qt::red );
    }

    path_drawn_ = true;
}

void ItemController::mousePressEvent( QGraphicsSceneMouseEvent * mouse_event )
{
    // выбранный итем
    QPointF cur_pos = mouse_event->scenePos();
    QGraphicsItem * cur_item = this->itemAt( cur_pos, QTransform() );
    GraphicItem * cast_item = static_cast< GraphicItem * >( cur_item );

    if( ! path_drawn_ )
        ResetPath();

    // TODO разбить на фукнции по событиям разных кликов
    if( mouse_event->button() == Qt::MouseButton::LeftButton ) // левая кнопка мыши
    {
        if( cast_item != nullptr && ( cast_item->GetRole() == Polaris::Role::ROOM ||
                                      cast_item->GetRole() == Polaris::Role::HALL ||
                                      cast_item->GetRole() == Polaris::Role::STAIR ) ) // выбор комнаты
        {
            SelectCurrentNode( cast_item );
            ResetPreviousNode();
            mark_down_.hide();
        }
        else if( cast_item != nullptr && cast_item->GetRole() == Polaris::Role::MARK ) // выбор марки
        {
            mark_down_.hide();
        }
        else if( cast_item == nullptr ) // клик по постому пространству экрана
        {
            // TODO reset all nodes
            ResetPreviousNode();
            mark_down_.setPos( cur_pos );
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
    QPointF cur_pos = mouse_event->scenePos();
    QGraphicsItem * cur_item = this->itemAt( cur_pos, QTransform() );
    GraphicItem * cast_item = static_cast< GraphicItem * >( cur_item );

    // TODO разбить на фукнции по событиям разных кликов
    if( mouse_event->button() == Qt::MouseButton::LeftButton )
    {
        if( cast_item != nullptr && ( cast_item->GetRole() == Polaris::Role::ROOM ||
                                      cast_item->GetRole() == Polaris::Role::HALL ||
                                      cast_item->GetRole() == Polaris::Role::STAIR ) ) // соединить ноды
        {
            if( cur_item != current_node_ ) // если соединение не с самим собой
            {
                SelectPreviousNode( cast_item );
                mark_down_.hide();
            }
        }
        else // сбросить соединение
        {
            ResetCurrentNode();
            ResetPreviousNode();
            // TODO метку не прячем. Когда перемещать метку
        }
    }
    // обновить сцену
    qInfo() << current_node_ << " : " << previous_node_;
    this->update();
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
    is_edit_ != is_edit_;
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
        return;
    }

    previous_node_ = new_current;
    previous_node_->SetSelection();
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