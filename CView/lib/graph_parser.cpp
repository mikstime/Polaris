#include <algorithm>
#include "include/graphic_connection.h"
#include "include/graphic_room.h"
#include "include/graph_parser.h"

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

}

void GraphParser::OnRoomAdded( const Meta & meta )
{
    // TODO проверить
    GraphicItem * nw_room =  new GraphicRoom( meta );
    item_cotroller_->addItem( nw_room );
    items_in_controller_.push_back( nw_room );

    SortItems();
}

void GraphParser::OnRoomRemoved( const Meta & meta )
{
//    auto cur_room = std::find_if(items_in_controller_.begin(),
//                                 items_in_controller_.end(),
//                                 [ meta ]( const GraphicItem * & item )
//                                 {
//                                     //return item->GetId() == meta.graph_node_id;
////                                TODO     Id a = 5;
////                                     Id b = 3;
////                                     return a == b;
//                                     return false;
//                                 });
//
//    if(cur_room != items_in_controller_.end() )
//    {
//        items_in_controller_.erase(cur_room );
//    }

    SortItems();
}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{
    // TODO проверить
//    auto from_room = std::find_if( items_in_controller_.begin(),
//                                   items_in_controller_.end(),
//                                   [ & connection ]( const GraphicItem * & item ) -> bool
//                                   {
//                                       return item->GetId() == connection.GetId();
//                                   });
//    auto to_room = std::find_if( items_in_controller_.begin(),
//                                 items_in_controller_.end(),
//                                 [ & connection ]( const GraphicItem * & item ) -> bool
//                                 {
//                                     return item->GetId() == connection.GetId();
//                                 });
//
//    GraphicItem * nw_connection =  new GraphicConnection( ( * from_room )->pos(),
//                                                          ( * to_room )->pos(),
//                                                          connection.GetId(),
//                                                          std::min( ( * from_room )->GetFloor(),
//                                                                    ( * to_room )->GetFloor() ) );
//    item_cotroller_->addItem( nw_connection );
//    items_in_controller_.push_back( nw_connection );

    SortItems();
}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection )
{
    // TODO
//    auto cur_connection = std::find_if( items_in_controller_.begin(),
//                              items_in_controller_.end(),
//                              [ & connection ]( const GraphicItem * & item ) -> bool
//                              {
//                                  return item->GetId() == connection.GetId();
//                              });
//
//    if( cur_connection != items_in_controller_.end() )
//    {
//        items_in_controller_.erase( cur_connection );
//    }

    SortItems();
}

void GraphParser::SortItems()
{
    //TODO
//    std::sort( items_in_controller_.begin(), items_in_controller_.end(),
//               []( const GraphicItem * & item_a, const GraphicItem * & item_b ) -> bool
//               {
//                   return item_a->GetId() < item_b->GetId();
//               });
}