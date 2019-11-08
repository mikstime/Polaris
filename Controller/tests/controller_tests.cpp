#include <gtest/gtest.h>
#include "controller.h"

class MockView : public QObject
{
    Q_OBJECT
signals:
    void ChooseRoom( int room_id );
    void ChooseConnection( int connection_id );
};

TEST( Controller, SetSelectedNode )
{
    MockView * view;
    Polaris::Controller * controller;
    QObject::connect( view, SIGNAL( ChooseRoom( int ) ), controller, SLOT( SetSelectedNode( int ) ) );

    EXPECT_EQ( controller->a_selected_node_id_, 0 );
    EXPECT_EQ( controller->b_selected_node_id_, 0 );

    view->ChooseRoom( 1 );
    EXPECT_EQ( controller->a_selected_node_id_, 1 );
    EXPECT_EQ( controller->b_selected_node_id_, 0 );

    view->ChooseRoom( 2 );
    EXPECT_EQ( controller->a_selected_node_id_, 2 );
    EXPECT_EQ( controller->b_selected_node_id_, 1 );

    view->ChooseRoom( 3 );
    EXPECT_EQ( controller->a_selected_node_id_, 3 );
    EXPECT_EQ( controller->b_selected_node_id_, 2 );
}

TEST( Controller, SetSelectedConnection )
{
    MockView * view;
    Polaris::Controller * controller;
    QObject::connect( view, SIGNAL( ChooseConnection( int ) ), controller, SLOT( SetSelectedConnection( int ) ) );

    EXPECT_EQ( controller->selected_connection_id_, 0 );

    view->ChooseConnection( 1 );
    EXPECT_EQ( controller->selected_connection_id_, 1 );

    view->ChooseRoom( 2 );
    EXPECT_EQ( controller->selected_connection_id_, 2 );

}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( & argc, argv );
    return RUN_ALL_TESTS();
}
