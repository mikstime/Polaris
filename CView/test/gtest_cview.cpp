#include <gtest/gtest.h>
#include "include/cgraphics_view.h"
#include <memory>
#include "mock_controller.h"
#include <QApplication>
#include <QMetaObject>
#include <QObject>
#include <QtTest/QtTest>

using Polaris::CGraphicsView;
using Polaris::CGraphicRoom;
using Polaris::CGraphicConnection;
using std::shared_ptr;

void MockController::SetSelectedNodes( int node_id )
{
    return;
}

void MockController::SetSelectedConnection( int connection_id )
{
    return;
}

void MockController::SaveChangedData( GraphNode node )
{
    return;
}

void MockController::SaveConnection( GraphConnection connection )
{
    return;
}

class ControllerIntegration : public ::testing::Test
{
protected:
    void SetUp()
    {
        mock_controller_ = std::shared_ptr< MockController >( new MockController );
        graphics_view_ = std::shared_ptr< CGraphicsView >( new CGraphicsView( nullptr ) );
    }

    std::shared_ptr< MockController > mock_controller_;
    std::shared_ptr< CGraphicsView > graphics_view_;
};

class ViewInvokeSlots : public ::testing::Test
{
protected:
    void SetUp()
    {
        graphics_view_ = std::shared_ptr< CGraphicsView >( new CGraphicsView( nullptr ) );
    }

    std::shared_ptr< CGraphicsView > graphics_view_;
};

TEST_F( ControllerIntegration, ConnectChooseRoom )
{
    ASSERT_TRUE( QObject::connect( graphics_view_.get(), SIGNAL( ChooseRoom( int ) ),
                                   mock_controller_.get(), SLOT( SetSelectedNodes( int ) ) ) );
}

TEST_F( ControllerIntegration, ConnectChooseConnection )
{
    ASSERT_TRUE( QObject::connect( graphics_view_.get(), SIGNAL( ChooseConnection( int ) ),
                                   mock_controller_.get(), SLOT( SetSelectedConnection( int ) ) ) );
}

TEST_F( ControllerIntegration, ConnectSaveChangeData )
{
    ASSERT_TRUE( QObject::connect( graphics_view_.get(), SIGNAL( SaveNewRoom( GraphNode ) ),
                                   mock_controller_.get(), SLOT( SaveChangedData( GraphNode ) ) ) );
}

TEST_F( ControllerIntegration, ConnectSaveConnection )
{
    ASSERT_TRUE( QObject::connect( graphics_view_.get(), SIGNAL( SaveNewConnection( GraphConnection ) ),
                                   mock_controller_.get(), SLOT( SaveConnection( GraphConnection ) ) ) );
}

TEST_F( ViewInvokeSlots, BuildItems )
{
    Meta meta;
    Graph graph;
    EXPECT_GT( QMetaObject::invokeMethod( graphics_view_.get(), "BuildItems",
                                          Q_ARG( Meta, meta ), Q_ARG( Graph, graph ) ), -1 );
    // cmp res to meta and graph
}

TEST_F( ViewInvokeSlots, DeleteRoom )
{
    Meta meta;
    Graph graph;
    QVector< int > change_list;
    EXPECT_GT( QMetaObject::invokeMethod( graphics_view_.get(), "RefreshItems",
                                          Q_ARG( Meta, meta ), Q_ARG( Graph, graph ),
                                          Q_ARG( QVector< int >, change_list ) ), -1 );
    // cmp res to meta and graph
}

TEST_F( ViewInvokeSlots, AddRoom )
{
    Meta meta;
    Graph graph;
    QVector< int > change_list;
    EXPECT_GT( QMetaObject::invokeMethod( graphics_view_.get(), "RefreshItems",
                                          Q_ARG( Meta, meta ), Q_ARG( Graph, graph ),
                                          Q_ARG( QVector< int >, change_list ) ), -1 );
    // cmp res to meta and graph
}

TEST_F( ViewInvokeSlots, DeleteConnection )
{
    Meta meta;
    Graph graph;
    QVector< int > change_list;
    EXPECT_GT( QMetaObject::invokeMethod( graphics_view_.get(), "RefreshItems",
                                          Q_ARG( Meta, meta ), Q_ARG( Graph, graph ),
                                          Q_ARG( QVector< int >, change_list ) ), -1 );
    // cmp res to meta and graph
}

TEST_F( ViewInvokeSlots, AddConnection )
{
    Meta meta;
    Graph graph;
    QVector< int > change_list;
    EXPECT_GT( QMetaObject::invokeMethod( graphics_view_.get(), "RefreshItems",
                                          Q_ARG( Meta, meta ), Q_ARG( Graph, graph ),
                                          Q_ARG( QVector< int >, change_list ) ), -1 );
    // cmp res to meta and graph
}

TEST_F( ViewInvokeSlots, DrawThePath )
{
    QVector< int > path;
    EXPECT_GT( QMetaObject::invokeMethod( graphics_view_.get(), "DrawThePath",
                                          Q_ARG( QVector< int >, path ) ), -1 );
    // cmp res to meta and graph
}

TEST( CGraphicRoom, Init )
{
    GraphNode room_info {};
    QRectF rect( 0, 0, 1, 1 );
    CGraphicRoom some_room( room_info, rect );

    // cmp new object and room_info
}

TEST( CGraphicConnection, Init )
{
    GraphConnection connection_info {};
    QLineF line( 0, 0, 1, 1 );
    CGraphicConnection some_connection( connection_info, line );

    // cmp new object and connection_info
}

TEST( CGraphicRoom, GetId )
{
    GraphNode room_info {};
    QRectF rect( 0, 0, 1, 1 );
    CGraphicRoom some_room( room_info, rect );

    // cmp new object and room_info
    // EXPECT_EQ( some_room.GetId(), room_info.id_ );
}

TEST( CGraphicConnection, GetId )
{
    GraphConnection connection_info {};
    QLineF line( 0, 0, 1, 1 );
    CGraphicConnection some_connection( connection_info, line );

    // cmp new object and connection_info
    // EXPECT_EQ( some_connection.GetId(), connection_info.id_ );
}

TEST( CGraphicConnection, GetPrice )
{
    GraphConnection connection_info {};
    QLineF line( 0, 0, 1, 1 );
    CGraphicConnection some_connection( connection_info, line );

    // cmp new object and connection_info
    // EXPECT_EQ( some_connection.GetPrice(), connection_info.price_ );
}

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
