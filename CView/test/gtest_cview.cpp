#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/graphic_connection.h"
#include "include/graph_parser.h"
#include "include/graphic_item.h"
#include "include/graphic_view.h"
#include "include/graphic_room.h"
#include "include/item_controller.h"
#include <memory>
#include "include/renderer.h"
#include "include/view.h"
#include "mock_controller.h"
#include <QApplication>


using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::GraphicConnection;
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

//TEST_F( ControllerIntegration, ConnectChooseRoom )
//{
//    ASSERT_TRUE( QObject::connect( graphics_view_.get(), &GraphicView::ChooseRoom ,
//                                   mock_controller_.get(), &MockController::SetSelectedNodes ) );
//}
//
//TEST_F( ControllerIntegration, ConnectChooseConnection )
//{
//    ASSERT_TRUE( QObject::connect( graphics_view_.get(), &GraphicView::ChooseConnection,
//                                   mock_controller_.get(), &MockController::SetSelectedConnection ) );
//}
//
//TEST_F( ControllerIntegration, ConnectSaveChangeData )
//{
//    ASSERT_TRUE( QObject::connect( graphics_view_.get(), &GraphicView::SaveNewRoom,
//                                   mock_controller_.get(), &MockController::SaveChangedData ) );
//}
//
//TEST_F( ControllerIntegration, ConnectSaveConnection )
//{
//    ASSERT_TRUE( QObject::connect( graphics_view_.get(), &GraphicView::SaveNewConnection,
//                                   mock_controller_.get(), &MockController::SaveConnection ) );
//}

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
    GraphicConnection some_connection( left, right );

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
    GraphicConnection some_connection( left, right );

    // cmp new object and connection_info
    // EXPECT_EQ( some_connection.GetId(), connection_info.id_ );
}

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
