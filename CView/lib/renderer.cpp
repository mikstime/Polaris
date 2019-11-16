#include "include/renderer.h"

using Polaris::Renderer;

Renderer::Renderer( QWidget * parent )
: QGraphicsView( parent )
{

}

short int Renderer::GetFloor() const
{
    return currnet_floor_;
}

void Renderer::wheelEvent( QWheelEvent * event )
{

}