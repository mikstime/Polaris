#include <algorithm>
#include "include/graphic_connection.h"
#include "include/graphic_room.h"
#include "include/graph_parser.h"

#include <QDebug>

using Polaris::GraphicItem;
using Polaris::GraphParser;
using std::shared_ptr;

GraphParser::GraphParser( shared_ptr< ItemController > & item_controller )
: item_cotroller_( item_controller )
{

}

GraphParser::~GraphParser()
{
    while( ! items_in_controller_.empty() )
        items_in_controller_.erase( items_in_controller_.begin() );
}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{

}

void GraphParser::OnPathFound( const std::vector< const GraphNode > & nodes,
                               const std::vector< const GraphConnection > & connections )
{

}

void GraphParser::OnRoomChanged( const Meta & meta )
{
    auto cur_room = FindItemById( meta.graph_node_id );

    if( cur_room != items_in_controller_.end() )
    {
        * static_cast< GraphicRoom * >( * cur_room ) = GraphicRoom( meta );
        item_cotroller_->update();
    } else
    {
        OnRoomAdded( meta );
    }
}

void GraphParser::OnRoomAdded( const Meta & meta )
{
    GraphicItem * nw_room =  new GraphicRoom( meta );
    item_cotroller_->addItem( nw_room );
    items_in_controller_.push_back( nw_room );

    // TODO заменить сорт на инсерт
    SortItems();
}

void GraphParser::OnRoomRemoved( const Meta & meta )
{
    EraseItemById( meta.graph_node_id );
}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{
    // TODO проверить
    auto from_room = FindItemById( connection.from );
    auto to_room = FindItemById( connection.to );

    if( from_room == items_in_controller_.end() || to_room == items_in_controller_.end() )
        return;

    GraphicItem * nw_connection =  new GraphicConnection( ( * from_room )->pos(),
                                                          ( * to_room )->pos(),
                                                          connection.GetId(),
                                                          std::min( ( * from_room )->GetFloor(),
                                                                    ( * to_room )->GetFloor() ) );
    item_cotroller_->addItem( nw_connection );
    items_in_controller_.push_back( nw_connection );

    // TODO заменить сорт на инсерт
    SortItems();
}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection )
{
    EraseItemById( connection.GetId() );
}

void GraphParser::SortItems()
{
    std::sort( items_in_controller_.begin(), items_in_controller_.end(),
               []( const GraphicItem * item_a, const GraphicItem * item_b ) -> bool
               {
                   return item_a->GetId() < item_b->GetId();
               });
}

std::vector< GraphicItem * >::iterator GraphParser::FindItemById( const Id cur_id )
{
    GraphicItem * find_item = new GraphicItem( cur_id );
    auto cur_item = std::lower_bound( items_in_controller_.begin(),
                                  items_in_controller_.end(),
                                  find_item,
                                  []( const GraphicItem * left, const GraphicItem * right )
                                  {
                                      return left->GetId() < right->GetId();
                                  });
    if( cur_item != items_in_controller_.end() && ( * cur_item )->GetId() == cur_id )
    {
        return cur_item;
    }
    else
    {
        return items_in_controller_.end();
    }
}

bool GraphParser::EraseItemById( const Id cur_id )
{
    auto cur_room = FindItemById( cur_id );

    if( cur_room != items_in_controller_.end() )
    {
        qInfo() << " ! ";
        item_cotroller_->removeItem( cur_room[ 0 ] );
        // TODO смартпоинтер?
        delete * cur_room;
        items_in_controller_.erase( cur_room );

        return true;
    }

    return false;
}