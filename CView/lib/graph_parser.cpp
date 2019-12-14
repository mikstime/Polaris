#include <algorithm>
#include "include/graphic_connection.h"
#include "include/graphic_room.h"
#include "include/graph_parser.h"

#include <QDebug>

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
    qInfo() << "Path";
    for( auto k : nodes )
    {
        qInfo() << k.room_number.c_str();
    }
    qInfo() << "Con";
    for( auto k : connections )
    {
        qInfo() << k.GetId();
    }

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

    for( const auto & k : connections )
    {
        auto cur_item = items_in_controller_->FindById( k.GetId() );

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
    qInfo() << "Change";

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
    item_controller_->addItem(nw_room );
    items_in_controller_->AddItem( nw_room, meta.graph_node_id );
}

void GraphParser::OnRoomRemoved( const Meta & meta )
{
    qInfo() << "Removed";

    item_controller_->ResetCurrentNode();
    item_controller_->ResetPreviousNode();
    EraseItem( meta.graph_node_id );
}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{
    // TODO проверить
    GraphicItem * from_room = items_in_controller_->FindById( connection.from );
    GraphicItem * to_room = items_in_controller_->FindById( connection.to );

    if( from_room == nullptr || to_room == nullptr )
        return;

    GraphicItem * nw_connection =  new GraphicConnection( from_room->pos(),
                                                          to_room->pos(),
                                                          connection.GetId(),
                                                          std::min( from_room->GetFloor(),
                                                                    to_room->GetFloor() ),
                                                                    connection.cost );
    item_controller_->addItem(nw_connection );
    items_in_controller_->AddItem(  nw_connection, connection.GetId() );
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
        // TODO проверить
        item_controller_->removeItem(cur_item );
//        auto pair = * cur_item;
//        item_cotroller_->removeItem( pair.second );
//        // TODO смартпоинтер?
//        delete pair.second;
//        items_in_controller_.erase( cur_item );
        delete cur_item;

        return true;
    }

    return false;
}