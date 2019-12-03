#include <QtCore/QObject>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "view_controller.h"

struct GraphicsView : public QObject
{
    virtual void GetSelectedNode() = 0;
};

struct MockGraphicsView : public GraphicsView
{
    MOCK_METHOD0( GetSelectedNode, void() );
};

struct ViewControllerTest : public ::testing::Test
{
    MockGraphicsView graphics_view_;
    Polaris::ViewController view_controller_;

    ViewControllerTest() {
        QObject::connect( & view_controller_, & Polaris::ViewController::GetSelectedNode,
                & graphics_view_, & MockGraphicsView::GetSelectedNode);
    }
};

TEST_F( ViewControllerTest, emitGetSelectedNode )
{
    EXPECT_CALL( graphics_view_, GetSelectedNode() );
    view_controller_.GetSelectedNode();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest( & argc, argv );
    return RUN_ALL_TESTS();
}
