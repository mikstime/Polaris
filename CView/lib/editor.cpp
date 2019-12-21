#include <algorithm>
#include "include/editor.h"
#include <QDebug>

using Polaris::Editor;

Editor::Editor( QGraphicsScene * scene )
: scene_( scene )
{

}

Editor::~Editor()
{
    ResetEditing();
    scene_.release();
}

void Editor::AddConnections( const QPolygonF & polygon, const QPointF & pos )
{
    for( const auto & k : polygon )
    {
        QPointF nw_pos = k + pos;
        GraphicItem * cur_item = static_cast< GraphicItem * >( scene_->itemAt( nw_pos, QTransform() ) );
        if( cur_item == nullptr || cur_item->GetRole() != Role::CONNECTION )
        {
            GraphicItem * nw_connection = new GraphicConnection( nw_pos );
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
    SelectConnection( nw_connection );
}

void Editor::SelectConnection( GraphicItem * const item )
{
    qInfo() << selected_.size() << ' ' << connections_.size();
    if( item->IsSelected() )
    {
        QPointF pos = item->pos();
        auto erase_from = std::find( selected_.begin(), selected_.end(), pos );
        for( auto k = erase_from; k < selected_.end(); k++ )
        {
            std::for_each( connections_.begin(), connections_.end(), [ & k ]( GraphicItem * a )
            {
                if( a->pos() == * k )
                    a->ResetSelection();
            }  );
        }
        selected_.erase( erase_from, selected_.end() );
    }
    else
    {
        item->SetSelection();
        selected_ << item->pos();
    }
    qInfo() << selected_.size() << ' ' << connections_.size();
}

void Editor::EraseItem( GraphicItem * const item )
{
    if( item->IsSelected() ) {
        QPointF pos = item->pos();
        auto erase_from = std::find( selected_.begin(), selected_.end(), pos );
        for( auto k = erase_from; k < selected_.end(); k++ )
        {
            std::for_each( connections_.begin(), connections_.end(), [ & k ]( GraphicItem * a )
            {
                if( a->pos() == * k )
                    a->ResetSelection();
            }  );
        }
        selected_.erase( erase_from, selected_.end() );
    }

    scene_->removeItem( item );
    selected_.erase( std::remove( selected_.begin(), selected_.end(), item->pos() ), selected_.end() );
    connections_.remove( item );
    delete item;
}

void Editor::ResetEditing()
{
    for( const auto & k : connections_ )
    {
        scene_->removeItem( k );
        delete k;
    }
    connections_.clear();
    selected_.erase( selected_.begin(), selected_.end() );
}

class AngleComparator
{
    QPointF origin_;
    QPointF dreference_;

    static double IsSamePoint( QPointF a, QPointF b ) { return a.x() * b.y() - a.y() * b.x(); }
public:
    AngleComparator( const QPointF origin, const QPointF reference ) : origin_( origin ), dreference_( reference - origin ) {}
    bool operator()( const QPointF a, const QPointF b ) const
    {
        const QPointF da = a - origin_, db = b - origin_;
        const double detb = IsSamePoint( dreference_, db );

        if ( detb == 0 && db.x() * dreference_.x() + db.y() * dreference_.y() >= 0 ) 
            return false;

        const double deta = IsSamePoint( dreference_, da );

        if ( deta == 0 && da.x() * dreference_.x() + da.y() * dreference_.y() >= 0 ) 
            return true;

        if ( deta * detb >= 0 ) 
        {
            return IsSamePoint( da, db ) > 0;
        }

        return deta > 0;
    }
};

QPolygonF Editor::GetNewForm()
{
//    if( selected_.size() > 3 )
//        std::sort( selected_.begin(), selected_.end(),
//                 AngleComparator( selected_.boundingRect().center(), selected_[0]) );
  
    return selected_.translated( - GetPos() );
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