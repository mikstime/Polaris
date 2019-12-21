#include <algorithm>
#include "include/graphic_connection.h"
#include "include/graphic_door.h"
#include "include/graphic_room.h"
#include "include/graph_parser.h"

using Polaris::GraphicDoor;
using Polaris::GraphicItem;
using Polaris::GraphParser;
using std::shared_ptr;

GraphParser::GraphParser( shared_ptr< ItemController > & item_controller,
                          shared_ptr< ItemCollaction > items_in_controller )
: item_controller_( item_controller ),
items_in_controller_( items_in_controller )
{

}

GraphParser::~GraphParser()
{
}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{
    // TODO потоки
    for( const auto & k : meta )
    {
        this->OnRoomAdded( k );
    }
    for( const auto & k : graph )
    {
        this->OnConnectionAdded( k );
    }
}

// TODO не объект нод, а объект меты
void GraphParser::DrawThePath( const std::vector< Meta > & nodes,
                               const std::vector< GraphConnection > & connections )
{
    // TODO полиморфизм. один вектор родительских объектов?
    std::vector< GraphicItem * > path;
    for( const auto & k : nodes )
    {
        GraphicItem * cur_item = items_in_controller_->FindById( k.graph_node_id );

        if( cur_item != nullptr )
        {
            path.push_back( cur_item );
        }
    }

    item_controller_->SetCurPath(path );
}

void GraphParser::OnRoomChanged( const Meta & meta )
{
    GraphicItem * cur_room = items_in_controller_->FindById( meta.graph_node_id );

    if( cur_room != nullptr )
    {
        GraphicRoom * cast_room = static_cast< GraphicRoom * >( cur_room );
        cast_room->SetMeta( meta );
        item_controller_->update();
    } else
    {
        OnRoomAdded( meta );
    }
}

void GraphParser::OnRoomAdded( const Meta & meta )
{
    GraphicItem * nw_room =  new GraphicRoom( meta );
    item_controller_->addItem( nw_room );
    items_in_controller_->AddItem( nw_room, meta.graph_node_id );
}

void GraphParser::OnRoomRemoved( const Meta & meta )
{
    item_controller_->ResetCurrentNode();
    item_controller_->ResetPreviousNode();
    EraseItem( meta.graph_node_id );
}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{
    if( items_in_controller_->FindById( connection.id_ ) != nullptr )
        return;

    GraphicItem * from_room = items_in_controller_->FindById( connection.from );
    GraphicItem * to_room = items_in_controller_->FindById( connection.to );

    if( from_room == nullptr || to_room == nullptr )
        return;

    if( from_room->GetRole() == Role::STAIR && to_room->GetRole() == Role::STAIR  )
        return;

    if( from_room->IsReacheble() && ! to_room->IsReacheble() )
    {
        to_room->SetReacheble( true );
    }
    else if( ! from_room->IsReacheble() && to_room->IsReacheble() )
    {
        from_room->SetReacheble( true );
    }

    const QPolygonF from_polygon = from_room->GetSize();
    const QPolygonF to_polygon = to_room->GetSize();

    QPointF left = { 0, 0 }, right = { 0, 0 };
    for( size_t i = 1; i < from_polygon.size(); i++ )
    {
        for( size_t j = 1; j < to_polygon.size(); j++ )
        {
//TODO  сделать оптимальнее
            if ( ( ( from_polygon[ i - 1 ] + from_room->pos() ) == ( to_polygon[ j - 1 ] + to_room->pos() ) &&
                    ( from_polygon[ i ] + from_room->pos() ) == ( to_polygon[ j ] + to_room->pos() ) ) ||
                 ( ( from_polygon[ i - 1 ] + from_room->pos() ) == ( to_polygon[ j ] + to_room->pos() ) &&
                   ( from_polygon[ i ] + from_room->pos() ) == ( to_polygon[ j - 1 ] + to_room->pos() ) ) )
            {
                left = from_polygon[ i - 1 ];
                right = from_polygon[ i ];
            }
        }
    }

    GraphicItem * nw_connection =  new GraphicDoor( connection.id_, from_room->GetFloor(), left, right );
    nw_connection->setPos( from_room->pos() );
    item_controller_->addItem( nw_connection );
    items_in_controller_->AddItem(  nw_connection, connection.GetId() );
    item_controller_->update();
}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection )
{
    item_controller_->ResetCurrentNode();
    item_controller_->ResetPreviousNode();
    EraseItem( connection.GetId() );
}

bool GraphParser::EraseItem( const Id cur_id )
{
    GraphicItem * cur_item = items_in_controller_->EraseItemById( cur_id );

    if( cur_item != nullptr )
    {
        item_controller_->removeItem( cur_item );
        item_controller_->update();
        delete cur_item;

        return true;
    }

    return false;
}