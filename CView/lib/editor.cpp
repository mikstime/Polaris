#include "include/editor.h"

using Polaris::Editor;

Editor::Editor( QGraphicsScene * scene )
: scene_( scene )
{

}

Editor::~Editor()
{
    FinishEditing();
    scene_.release();
}


void Editor::AddConnections( const QPolygonF & polygon )
{
    for( const auto & k : polygon )
    {
        GraphicItem * cur_item = static_cast< GraphicItem * >( scene_->itemAt( k, QTransform() ) );
        if( cur_item == nullptr && cur_item->GetRole() != Role::CONNECTION )
        {
            GraphicItem * nw_connection = new GraphicConnection( k );
            connections_.push_back( nw_connection );
            scene_->addItem( nw_connection );
        }
    }
}

void Editor::AddConnection( QPointF & pos )
{
    GraphicItem * nw_connection = new GraphicConnection( pos );
    connections_.push_back( nw_connection );
    scene_->addItem( nw_connection );
}

void Editor::SelectConnection( GraphicItem * const item )
{
    if( item->IsSelected() )
    {
        item->ResetSelection();
        //TODO доделать
        selected_.erase( std::remove( selected_.begin(), selected_.end(), item->pos() ), selected_.end() );
    }
    else
    {
        item->SetSelection();
        selected_.push_back( item->pos() );
    }
}

void Editor::EraseItem( GraphicItem * const item )
{
    scene_->removeItem( item );
    selected_.erase( std::remove( selected_.begin(), selected_.end(), item->pos() ), selected_.end() );
    connections_.remove( item );
    delete item;
}

void Editor::FinishEditing()
{
    for( const auto & k : connections_ )
    {
        scene_->removeItem( k );
        delete k;
    }
    connections_.clear();
    selected_.erase( selected_.begin(), selected_.end() );
}

QPolygonF Editor::GetNewForm() const
{
    QPolygonF res;
    for( const auto & k : selected_ )
    {
        res.push_back( k );
    }
    return res;
}

QPointF Editor::GetPos() const
{
    if( selected_.empty() )
    {
        return QPointF( 0, 0 );
    }
    QPointF res = selected_[ 0 ];
    for( const auto & k : selected_ )
    {
        if( k.x() < res.x() )
        {
            res.setX( k.x() );
        }
        if ( k.y() < res.y() )
        {
            res.setY( k.y() );
        }
    }
    return res;
}