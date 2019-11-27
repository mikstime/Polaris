#include "include/graphic_item.h"
#include "include/renderer.h"
#include <QWheelEvent>

using Polaris::Renderer;

Renderer::Renderer( QGraphicsScene * scene, QWidget * parent )
: QGraphicsView( scene, parent ),
current_floor_( 1 ),
empty_first_floor_( true ),
empty_last_floor_( true )
{
    // TODO инициализация начальной картинки
}

short int Renderer::GetFloor() const
{
    return current_floor_;
}

void Renderer::wheelEvent( QWheelEvent * event )
{
    // Если смена этажа успешна, то он не пустой
    if( event->delta() > 0 && ! empty_last_floor_ )
    {
        empty_last_floor_ = ! ChangeFloor( 1 );
    }
    else if ( event->delta() < 0 && ! empty_first_floor_ )
    {
        empty_first_floor_ = ! ChangeFloor( -1 );
    }

    if( FloorEmpty() )
    {
        RaiseEmptyFloor();
    }
}

void Renderer::mousePressEvent( QMouseEvent * event )
{
    // TODO перемещение сцены мышью
    if (event->button() == Qt::MiddleButton)
    {
//        // Store original position.
//        m_originX = event->x();
//        m_originY = event->y();
    }
}

void Renderer::mouseMoveEvent( QMouseEvent * event )
{
//    if (e->buttons() & Qt::MidButton)
//    {
//        QPointF oldp = mapToScene(m_originX, m_originY);
//        QPointF newP = mapToScene(event->pos());
//        QPointF translation = newp - oldp;
//
//        translate(translation.x(), translation.y());
//
//        m_originX = event->x();
//        m_originY = event->y();
//    }
}

bool Renderer::ChangeFloor( const int8_t & step )
{
    // новый этаж и лист всех элементов
    bool floor_exists = false;
    QList< QGraphicsItem * > && items_list = this->scene()->items();

    for( size_t i = 0; i < items_list.size(); ++i )
    {
        // каст к кастомному элементу
        GraphicItem * cur_item = qgraphicsitem_cast< GraphicItem * >( items_list[ i ] );

        // если элемент на этаже, показать, иначе спрятать
        if( cur_item->GetFloor() != current_floor_ + step )
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

bool Renderer::FloorEmpty()
{
    return empty_first_floor_ || empty_last_floor_;
}

void Renderer::RaiseEmptyFloor()
{
    // TODO подменить фон
}