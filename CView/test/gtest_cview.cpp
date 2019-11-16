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
#include "include/renderer.h"
#include "include/view.h"
#include <QApplication>

using Polaris::GraphParser;
using Polaris::GraphicConnection;
using Polaris::GraphicItem;
using Polaris::GraphicRoom;
using Polaris::GraphicView;
using Polaris::ItemController;
using Polaris::Renderer;
using Polaris::View;

using std::shared_ptr;

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class ControllerIntegration : public ::testing::Test
{
protected:
    void SetUp()
    {
        mock_controller_ = std::shared_ptr< MockController >( new MockController );
        graphics_view_ = std::shared_ptr< GraphicView >(new GraphicView() );
    }

    std::shared_ptr< MockController > mock_controller_;
    std::shared_ptr< GraphicView > graphics_view_;
};

class ViewInvoke : public ::testing::Test
{
protected:
    void SetUp()
    {
        graphics_view_ = std::shared_ptr< GraphicView >(new GraphicView() );
    }

    std::shared_ptr< GraphicView > graphics_view_;
};


TEST_F( ViewInvoke, BuildItems )
{
    Meta meta;
    GraphConnection graph;
    graphics_view_.get()->BuildItems( meta, graph );

    // cmp res to meta and graph
}

TEST_F( ViewInvoke, DeleteRoom )
{
    Meta meta;
    QVector< size_t > change_list;
    graphics_view_.get()->RefreshItems( meta, change_list );

    // cmp res to meta and graph
}

TEST_F( ViewInvoke, AddRoom )
{
    Meta meta;
    QVector< size_t > change_list;
    graphics_view_.get()->RefreshItems( meta, change_list );

    // cmp res to meta and graph
}

TEST_F( ViewInvoke, DeleteConnection )
{
    Meta meta;
    QVector< size_t > change_list;
    graphics_view_.get()->RefreshItems( meta, change_list );

    // cmp res to meta and graph
}

TEST_F( ViewInvoke, AddConnection )
{
    Meta meta;
    QVector< size_t > change_list;
    graphics_view_.get()->RefreshItems( meta, change_list );

    // cmp res to meta and graph
}

TEST_F( ViewInvoke, DrawThePath )
{
    QVector< size_t > path;
    graphics_view_.get()->DrawThePath( path );

    // cmp res to meta and graph
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

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
