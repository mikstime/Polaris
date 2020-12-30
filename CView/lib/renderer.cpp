#include "include/graphic_item.h"
#include "include/renderer.h"
#include <QScrollBar>
#include <QWheelEvent>

using Polaris::Renderer;

Renderer::Renderer( QGraphicsScene * scene, QWidget * parent )
: QGraphicsView( scene, parent ),
current_floor_( 1 ),
min_floor_( 1 ),
max_floor_( 1 ),
middle_mouse_pressed_( false )
{
    this->setBackgroundBrush(QBrush( "#2E2E2E", Qt::SolidPattern ) );
    this->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    this->setSceneRect( 0, 0, this->size().width() * 2, this->size().height() * 2 );
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
}

bool Renderer::FloorUp()
{
    return ChangeFloor( 1 );
}

bool Renderer::FloorDown()
{
    return ChangeFloor( -1 );
}

void Renderer::wheelEvent( QWheelEvent *event)
{
    if ( event->modifiers() == Qt::ControlModifier /*&& event->angleDelta().x() == 0*/ )
    {
        QPoint pos = event->pos();
        QPointF posf = this->mapToScene( pos );

        double by;
        double angle =event->angleDelta().y();

        if( angle > 0 )
        {
            by = 1 + ( angle / 360 * 0.1 );
        }
        else if( angle < 0 )
        {
            by = 1 + (angle / 360 * 0.1);
        }
        else
        {
            by = 1;
        }

        this->scale(by, by);

        double w = this->viewport()->width();
        double h = this->viewport()->height();

        double wf = this->mapToScene( QPoint( w - 1, 0 ) ).x()
                    - this->mapToScene(QPoint( 0,0 ) ).x();
        double hf = this->mapToScene(QPoint( 0, h - 1 ) ).y()
                    - this->mapToScene( QPoint( 0,0 ) ).y();

        double lf = posf.x() - pos.x() * wf / w;
        double tf = posf.y() - pos.y() * hf / h;

        this->ensureVisible( lf, tf, wf, hf, 0, 0 );

        QPointF newPos = this->mapToScene( pos );

        this->ensureVisible( QRectF( QPointF( lf, tf ) - newPos + posf,
                                   QSizeF( wf, hf) ), 0, 0 );

       event->accept();
    }
    else
    {
        QGraphicsView::wheelEvent( event );
    }
}

void Renderer::mousePressEvent( QMouseEvent * event )
{
    if( event->button() == Qt::MiddleButton )
    {
        middle_mouse_pressed_ = true;
        start_point_ = event->pos();
        setCursor( Qt::ClosedHandCursor );
        event->accept();
    }
    else
    {
        QGraphicsView::mousePressEvent( event );
    }
}

void Renderer::mouseReleaseEvent(QMouseEvent *event)
{
    if( event->button() == Qt::MiddleButton )
    {
        middle_mouse_pressed_ = false;
        setCursor( Qt::ArrowCursor );
        event->accept();
    }
    else
    {
        QGraphicsView::mouseReleaseEvent( event );
    }
}

void Renderer::mouseMoveEvent(QMouseEvent *event)
{
    if( middle_mouse_pressed_ )
    {
        horizontalScrollBar()->setValue( horizontalScrollBar()->value() - ( event->x() - start_point_.x() ) );
        verticalScrollBar()->setValue( verticalScrollBar()->value() - ( event->y() - start_point_.y() ) );
        start_point_ = event->pos();
        event->accept();
    }
    else
    {
        QGraphicsView::mouseMoveEvent( event );
    }
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
        GraphicItem * cur_item = qgraphicsitem_cast< GraphicItem * >( items_list[ i ] );

        if( cur_item->GetFloor() != current_floor_ )
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