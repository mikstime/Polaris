#include "include/renderer.h"

using Polaris::Renderer;

Renderer::Renderer( QGraphicsScene * scene, QWidget * parent )
: QGraphicsView( scene, parent ),
current_floor_( 1 )
{

}

short int Renderer::GetFloor() const
{
    return current_floor_;
}

void Renderer::wheelEvent( QWheelEvent * event )
{

}