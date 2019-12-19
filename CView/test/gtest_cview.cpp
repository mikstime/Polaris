#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/graphic_connection.h"
#include "include/item_collaction.h"
#include "mock_controller.h"
#include "mock_graphic_item.h"
#include "mock_parser.h"
#include "mock_renderer.h"
#include "mock_view.h"
#include <memory>
#include <QApplication>

using Polaris::GraphConnection;
using Polaris::GraphicConnection;
using Polaris::GraphParser;
using Polaris::GraphicItem;
using Polaris::GraphicRoom;
using Polaris::GraphicView;
using Polaris::ItemController;
using Polaris::ItemCollaction;
using Polaris::Meta;
using Polaris::Renderer;
using Polaris::Role;

using std::shared_ptr;

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::SetArgReferee;
using ::testing::Return;
using ::testing::_;

TEST( Item, Init )
{
    GraphicItem item( 1, 5, Role::HALL );

    EXPECT_EQ( item.GetId(), 1 );
    EXPECT_EQ( item.GetFloor(), 5 );
    EXPECT_EQ( item.GetRole(), Polaris::Role::HALL );
}

TEST( Room, Init )
{
    Meta meta = { 1, "805", "Лаборатория", QPointF( 1, 1 ),
                  QPolygonF( 0 ), 5, Role::ROOM };
    GraphicRoom room( meta );

    EXPECT_EQ( room.GetId(), 1 );
    EXPECT_EQ( room.GetFloor(), 5 );
    EXPECT_EQ( room.GetRole(), Polaris::Role::ROOM );
    EXPECT_EQ( room.GetInfo(), "Лаборатория" );
    EXPECT_EQ( room.GetRoom(), "805" );
}

TEST( Connection, Init )
{
    QPointF point( 50, 50 );
    GraphicConnection connection( point );

    EXPECT_EQ( connection.GetId(), 1 );
    EXPECT_EQ( connection.GetFloor(), 2 );
    EXPECT_EQ( connection.GetRole(), Polaris::Role::CONNECTION );
}

TEST( Room, Color )
{
    Meta meta = { 1, "805", QPointF( 1, 1 ),
                  QPolygonF( 0 ), 5, Role::ROOM };
    GraphicRoom room( meta );

    QColor cur_color = room.GetColor();

    room.SetColor( Qt::black );
    EXPECT_NE( room.GetColor(), cur_color );
    EXPECT_EQ( room.GetColor(), Qt::black );

    room.SetDefaultColor();
    EXPECT_EQ( room.GetColor(), cur_color );

    room.SetSelection();
    EXPECT_NE( room.GetColor(), cur_color );

    room.ResetSelection();
    EXPECT_EQ( room.GetColor(), cur_color );
}

TEST( Connection, Color )
{
    QPointF point( 50, 50 );
    GraphicConnection connection( point );

    QColor cur_color = connection.GetColor();
    connection.SetColor( Qt::blue );
    EXPECT_NE( connection.GetColor(), cur_color );
    EXPECT_EQ( connection.GetColor(), Qt::blue );

    connection.SetDefaultColor();
    EXPECT_EQ( connection.GetColor(), cur_color );

    connection.SetSelection();
    EXPECT_NE( connection.GetColor(), cur_color );

    connection.ResetSelection();
    EXPECT_EQ( connection.GetColor(), cur_color );
}

TEST( Renderer, Floor )
{

    ItemController item_controller( QRect( 0, 0, 500, 500 ), nullptr );
    Renderer renderer( & item_controller );

    renderer.SetFloor( 5 );
    EXPECT_EQ( renderer.GetFloor(), 5 );
}

class Parser : public ::testing::Test
{
protected:
    void SetUp()
    {
        items_in_controller_ = std::shared_ptr< ItemCollaction >( new ItemCollaction );
        item_controller_ = std::shared_ptr< ItemController >( new ItemController( QRect( 0, 0,
                                                                                     500, 500 ), items_in_controller_ ) );
        graph_parser_ = std::shared_ptr< GraphParser >( new GraphParser( item_controller_, items_in_controller_ ) );

        for( size_t i = 0; i < 10; i++ )
        {
            Meta meta = { i, "805ю", QPointF( 20, 20 ),
                          QPolygonF( 0 ), 1, Role::ROOM };
            meta_.push_back( meta );
        }
        for( size_t i = 1; i < 5; i++ )
        {
            GraphConnection connection( i + 10 );
            connection.from = i;
            connection.to = i * 2;
            graph_.push_back( connection );
        }
    }

    std::vector< Meta > meta_;
    std::vector< GraphConnection > graph_;
    std::shared_ptr< GraphParser > graph_parser_;
    std::shared_ptr< ItemController > item_controller_;
    std::shared_ptr< ItemCollaction > items_in_controller_;
};

TEST_F( Parser, BuildItems )
{
    graph_parser_->BuildItems( meta_, graph_ );

    EXPECT_EQ( item_controller_->items().size(), 15 );
}

TEST_F( Parser, AddRoom )
{
    graph_parser_->OnRoomAdded( meta_[ 0 ] );
    EXPECT_EQ( item_controller_->items().size(), 2 );

    graph_parser_->OnRoomRemoved( meta_[ 0 ] );
    EXPECT_EQ( item_controller_->items().size(), 1 );
}

TEST_F( Parser, AddConnection )
{
    graph_parser_->OnRoomAdded( meta_[ 1 ] );
    graph_parser_->OnRoomAdded( meta_[ 2 ] );
    graph_parser_->OnConnectionAdded( graph_[ 0 ] );
    EXPECT_EQ( item_controller_->items().size(), 4 );

    graph_parser_->OnConnectionRemoved( graph_[ 0 ] );
    EXPECT_EQ( item_controller_->items().size(), 3 );
}

class GraphView : public ::testing::Test
{
protected:
    void SetUp()
    {
        graphic_view_ = shared_ptr< GraphicView >( new GraphicView() );
        graph_parser_ = shared_ptr< MockGraphParser >( new MockGraphParser() );
        // TODO моки
    }

    std::shared_ptr< GraphicView > graphic_view_;
    std::shared_ptr< MockGraphParser > graph_parser_;
};

TEST_F( GraphView, Parser )
{
//    EXPECT_CALL( *( graph_parser_.get() ), OnRoomChanged( _ ) ).Times( 1 );
//    Meta meta = {};
//    graphic_view_->AddRoom( meta );
}

//class MouseInteraction : public ::testing::Test
//{
//protected:
//    void SetUp()
//    {
//        // TODO тестирование взяимодействия с мышью
//    }
//};

int main(int argc, char** argv) {
    QApplication a(argc, argv, false );
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
