#include "include/graphic_item.h"
#include "include/renderer.h"
#include <QWheelEvent>

using Polaris::Renderer;

Renderer::Renderer( QGraphicsScene * scene, QWidget * parent )
: QGraphicsView( scene, parent ),
current_floor_( 1 ),
min_floor_( 1 ),
max_floor_( 1 )
{
    this->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setSceneRect( 0, 0, this->size().width() - 5, this->size().height() - 5 );
}

int8_t Renderer::GetFloor() const
{
    return current_floor_;
}

void Renderer::SetFloor( const int8_t floor )
{
    if( floor < min_floor_ )
    {
        min_floor_ = floor;
    } else if ( floor > max_floor_ )
    {
        max_floor_ = floor;
    }
    current_floor_ = floor;
}

bool Renderer::FloorUp()
{
    return ChangeFloor( 1 );
}

bool Renderer::FloorDown()
{
    return ChangeFloor( -1 );
}

void Renderer::wheelEvent( QWheelEvent * event )
{
}

bool Renderer::ChangeFloor( const int8_t step )
{
    if( NextFloorEmpty( step ) )
    {
        RaiseEmptyFloor();
        return false;
    } else
    {
        RedrawFloor( step );
    }

    return true;
}

bool Renderer::RedrawFloor(const int8_t step )
{
    current_floor_ += step;
    bool floor_exists = false;
    QList< QGraphicsItem * > && items_list = this->scene()->items();

    for( size_t i = 0; i < items_list.size(); ++i )
    {
        // TODO лестница на несколько этажей
        GraphicItem * cur_item = qgraphicsitem_cast< GraphicItem * >( items_list[ i ] );

        if( cur_item->GetFloor() != current_floor_ && cur_item->GetRole() != Role::STAIR )
        {
            cur_item->hide();
        }
        else
        {
            cur_item->show();
            floor_exists = true;
        }
    }

    return floor_exists;
}

bool Renderer::NextFloorEmpty( const int8_t step )
{
    return ( current_floor_ + step ) > ( max_floor_ + 1 ) || ( current_floor_ + step ) < ( min_floor_ - 1 );
}

void Renderer::RaiseEmptyFloor()
{
}