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
    // TODO другой erase
    while( ! items_in_controller_.empty() )
        items_in_controller_.erase( items_in_controller_.begin() );
}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{
    // TODO собирается карта
}

// TODO не объект нод, а объект меты
void GraphParser::DrawThePath( const std::vector< GraphNode > & nodes,
                               const std::vector< GraphConnection > & connections )
{
    // TODO полиморфизм. один вектор родительских объектов?
    std::vector< GraphicItem * > path;
    for( const auto & k : nodes )
    {
        auto cur_item = items_in_controller_.find( k.GetId() );

        if( cur_item != items_in_controller_.end() )
        {
            path.push_back( ( * cur_item ).second );
        }
    }

    for( const auto & k : connections )
    {
        auto cur_item = items_in_controller_.find( k.GetId() );

        if( cur_item != items_in_controller_.end() )
        {
            path.push_back( ( * cur_item ).second );
        }
    }

    item_cotroller_->SetCurPath( path );
}

void GraphParser::OnRoomChanged( const Meta & meta )
{
    auto cur_room = items_in_controller_.find( meta.graph_node_id );

    if( cur_room != items_in_controller_.end() )
    {
        * static_cast< GraphicRoom * >( ( * cur_room ).second ) = GraphicRoom( meta );
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
    items_in_controller_.insert( std::make_pair( meta.graph_node_id, nw_room ) );
}

void GraphParser::OnRoomRemoved( const Meta & meta )
{
    EraseItemById( meta.graph_node_id );
}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{
    // TODO проверить
    auto from_room = items_in_controller_.find( connection.from );
    auto to_room = items_in_controller_.find( connection.to );

    if( from_room == items_in_controller_.end() || to_room == items_in_controller_.end() )
        return;

    GraphicItem * nw_connection =  new GraphicConnection( ( * from_room ).second->pos(),
                                                          ( * to_room ).second->pos(),
                                                          connection.GetId(),
                                                          std::min( ( * from_room ).second->GetFloor(),
                                                                    ( * to_room ).second->GetFloor() ) );
    item_cotroller_->addItem( nw_connection );
    items_in_controller_.insert( std::make_pair( connection.GetId(), nw_connection ) );
}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection )
{
    EraseItemById( connection.GetId() );
}

std::unordered_map< Polaris::Id, GraphicItem * >::iterator GraphParser::FindByPointer( const GraphicItem * const cur_pointer )
{
    auto cur_item = std::find_if( items_in_controller_.begin(),
                                  items_in_controller_.end(),
                                  [ & cur_pointer ]( std::pair< Id, GraphicItem * > value )
                                  {
                                      return value.second == cur_pointer;
                                  });
    return cur_item;
}

bool GraphParser::EraseItemById( const Id cur_id )
{
    auto cur_item = items_in_controller_.find( cur_id );

    if( cur_item != items_in_controller_.end() )
    {
        qInfo() << " ! ";
        auto pair = * cur_item;
        item_cotroller_->removeItem( pair.second );
        // TODO смартпоинтер?
        delete pair.second;
        items_in_controller_.erase( cur_item );

        return true;
    }

    return false;
}