#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/graph_parser.h"
#include "include/graphic_connection.h"
#include "include/graphic_item.h"
#include "include/graphic_room.h"
#include "include/graphic_view.h"
#include "include/item_controller.h"
#include <memory>
#include "mock_controller.h"
#include "mock_graphic_item.h"
#include "mock_view.h"
#include "include/renderer.h"
#include "include/view.h"
#include "include/view_sub.h"
#include "mock_view.h"
#include <QApplication>

using Polaris::GraphParser;
using Polaris::GraphConnection;
using Polaris::GraphicConnection;
using Polaris::GraphicItem;
using Polaris::GraphicRoom;
using Polaris::GraphicView;
using Polaris::ItemController;
using Polaris::Meta;
using Polaris::Renderer;
using Polaris::View;
using Polaris::ViewSub;

using std::shared_ptr;

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::SetArgReferee;
using ::testing::Return;
using ::testing::_;

class ViewIntegration : public ::testing::Test
{
protected:
    void SetUp()
    {
        graphics_view_ = std::shared_ptr< GraphicView >(new GraphicView() );
    }

    std::vector< Meta > meta;
    std::vector< GraphConnection > graph;
    std::shared_ptr< GraphicView > graphics_view_;
};

class ItemGetters : public ::testing::Test
{
protected:
    void SetUp()
    {
        controller_ = shared_ptr< ItemController >( new ItemController( QRectF( 0, 0,
                                                                                          200, 200 ) ) );
        renderer_ = shared_ptr< Renderer >( new Renderer( nullptr ) );
        renderer_->setScene( controller_.get() );
    }

    std::shared_ptr< ItemController > controller_;
    std::shared_ptr< Renderer > renderer_;
    MockGraphicItem item;

};

class GraphParserTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        controller_ = shared_ptr< ItemController >( new ItemController( QRectF( 0, 0,
                                                                                200, 200 ) ) );
        renderer_ = shared_ptr< Renderer >( new Renderer( nullptr ) );
        renderer_->setScene( controller_.get() );
    }

    std::shared_ptr< ItemController > controller_;
    std::shared_ptr< Renderer > renderer_;
    MockGraphicItem item;

};

class ViewSubIntegration : public ::testing::Test
{
protected:
    void SetUp()
    {
        view_ = shared_ptr< MockView >( new MockView() );
        view_sub_ = shared_ptr< ViewSub >( new ViewSub( view_.get() ) );
    }

    std::vector< size_t > path;
    std::vector< Meta > meta;
    std::vector< GraphConnection > graph;
    std::shared_ptr< ViewSub > view_sub_;
    std::shared_ptr< MockView > view_;

};

TEST_F( GraphParserTest, BuildItems )
{
    ItemController controller( QRectF( 0, 0, 200, 200 ) );
    std::vector< Meta > meta;
    std::vector< GraphConnection > graph;
    GraphParser parser( & controller );

    // cmp controller.items()
}

TEST( GraphicRoom, Init )
{
    Meta room_info {};
    QRectF rect( 0, 0, 1, 1 );
    GraphicRoom some_room( room_info, rect );

    // cmp new object and room_info
}

TEST( GraphicConnection, Init )
{
    QPointF left( 0, 1 );
    QPointF right( 1, 2 );
    GraphConnection connection_info{};
    GraphicConnection some_connection( left, right, connection_info );

    // cmp new object and connection_info
}

TEST( GraphicRoom, GetId )
{
    Meta room_info {};
    QRectF rect( 0, 0, 1, 1 );
    GraphicRoom some_room( room_info, rect );

    // cmp new object and room_info
    // EXPECT_EQ( some_room.GetId(), room_info.id_ );
}

TEST( GraphicConnection, GetId )
{
    QPointF left( 0, 1 );
    QPointF right( 1, 2 );
    GraphConnection connection_info{};
    GraphicConnection some_connection( left, right, connection_info );

    // cmp new object and connection_info
    // EXPECT_EQ( some_connection.GetId(), connection_info.id_ );
}

TEST_F( ItemGetters, GetId )
{
    EXPECT_CALL( item, GetId() ).WillOnce( Return( 1 ) );

    controller_->addItem( & item );
    GraphicItem * res = qgraphicsitem_cast< GraphicItem * > ( controller_->items()[ 0 ] );
    EXPECT_EQ( res->GetId(), 1 );
}

TEST_F( ItemGetters, GetFloor )
{
    EXPECT_CALL( item, GetFloor() ).WillOnce( Return( 1 ) );

    controller_->addItem( & item );
    GraphicItem * res = qgraphicsitem_cast< GraphicItem * > ( controller_->items()[ 0 ] );
    EXPECT_EQ( res->GetFloor(), 1 );
}

TEST_F( ItemGetters, GetRole )
{
    EXPECT_CALL( item, GetRole() ).WillOnce( Return( "room" ) );

    controller_->addItem( & item );
    GraphicItem * res = qgraphicsitem_cast< GraphicItem * > ( controller_->items()[ 0 ] );
    EXPECT_EQ( res->GetRole(), "room" );
}

// реакция на изменения в модели
TEST_F( ViewIntegration, BuildItems )
{
    graphics_view_->BuildItems( meta, graph );

    // cmp res to meta and graph
}

TEST_F( ViewIntegration, DeleteRoom )
{
    graphics_view_->OnMetaRemoved( meta[ 1 ] );

    // cmp res to meta and graph
}

TEST_F( ViewIntegration, AddRoom )
{
    Meta nw{};
    graphics_view_->OnMetaAdded( nw );
    // cmp res to meta and graph
}

TEST_F( ViewIntegration, DeleteConnection )
{
    graphics_view_->OnConnectionRemoved( graph[ 1 ] );

    // cmp res to meta and graph
}

TEST_F( ViewIntegration, AddConnection )
{
    GraphConnection nw{};
    graphics_view_->OnConnectionAdded( nw );

    // cmp res to meta and graph
}

TEST_F( ViewIntegration, DrawThePath )
{
    std::vector< size_t > path;
    graphics_view_->DrawThePath( path );

    // cmp res to meta and graph
}

TEST_F( ViewSubIntegration, BuildItems )
{
    EXPECT_CALL( * view_.get(), BuildItems( _, _ ) ).Times( 1 );

    view_sub_->BuildItems( meta, graph );
}

TEST_F( ViewSubIntegration, DrawThePath )
{
    EXPECT_CALL( * view_.get(), DrawThePath( _ ) ).Times( 1 );

    view_sub_->DrawThePath( path );
}

TEST_F( ViewSubIntegration, OnMetaChanged )
{
    EXPECT_CALL( * view_.get(), OnMetaChanged( _ ) ).Times( 1 );

    view_sub_->OnMetaChanged( meta[ 1 ] );
}

TEST_F( ViewSubIntegration, OnMetaAdded )
{
    EXPECT_CALL( * view_.get(), OnMetaAdded( _ ) ).Times( 1 );

    view_sub_->OnMetaAdded( meta[ 1 ] );
}

TEST_F( ViewSubIntegration, OnMetaRemoved )
{
    EXPECT_CALL( * view_.get(), OnMetaRemoved( _ ) ).Times( 1 );

    view_sub_->OnMetaRemoved( meta[ 1 ] );
}

TEST_F( ViewSubIntegration, OnConnectionAdded )
{
    EXPECT_CALL( * view_.get(), OnConnectionAdded( _ ) ).Times( 1 );

    view_sub_->OnConnectionAdded( graph[ 1 ] );
}

TEST_F( ViewSubIntegration, OnConnectionRemoved )
{
    EXPECT_CALL( * view_.get(), OnConnectionRemoved( _ ) ).Times( 1 );

    view_sub_->OnConnectionRemoved( graph[ 1 ] );
}

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
