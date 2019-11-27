#include "include/graphic_item.h"
#include "include/renderer.h"
#include <QWheelEvent>

using Polaris::Renderer;

Renderer::Renderer( QGraphicsScene * scene, QWidget * parent )
: QGraphicsView( scene, parent ),
current_floor_( 1 )
{
    // TODO инициализация начальной картинки
}

short int Renderer::GetFloor() const
{
    return current_floor_;
}

void Renderer::wheelEvent( QWheelEvent * event )
{
    if( event->delta() > 0 )
    {
        ChangeFloor( 1 );
    }
    else if ( event->delta() < 0 )
    {
        ChangeFloor( -1 );
    }

}

void Renderer::ChangeFloor( const int8_t & step )
{
    // новый этаж и лист всех элементов
    int8_t tmp_floor = current_floor_ + step;
    QList< QGraphicsItem * > && items_list = this->scene()->items();

    for( size_t i = 0; i < items_list.size(); ++i )
    {
        // каст к кастомному элементу
        GraphicItem * cur_item = qgraphicsitem_cast< GraphicItem * >( items_list[ i ] );

        // если элемент на этаже, показать, иначе спрятать
        if( cur_item->GetFloor() != tmp_floor )
        {
            cur_item->hide();
        }
        else
        {
            cur_item->show();
            current_floor_ = tmp_floor;
        }
    }

    // TODO проверка на существование этажа +-1
}