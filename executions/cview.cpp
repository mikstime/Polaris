#include "includes/cview.h"

using namespace Polaris;

CGraphicsView::CGraphicsView( QWidget *parent )
    :
      QGraphicsView( parent )
{

}

void CGraphicsView::BuildItems( const Meta & new_meta, const Graph & new_graph )
{

}

void CGraphicsView::RefreshItems( const Meta & new_meta, const Graph & new_graph,
                   QVector< int > rooms_change_list)
{

}

void CGraphicsView::DrawThePath( QVector< int > path )
{

}

void CGraphicsView::CreateNewConnectin()
{

}

void CGraphicsView::CreateNewRoomMeta()
{

}

void CGraphicsView::ChangeRoomMeta()
{

}
