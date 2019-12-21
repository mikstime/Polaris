#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "include/view_controller.h"
#include "include/graphic_view.h"

using Polaris::ViewController;
using Polaris::GraphicView;

class MockGraphicView : public GraphicView
{
    MOCK_METHOD0( GetFloorNumber, void() );
};

TEST( ViewController, Floor )
{
    MockGraphicView view;
    ViewController view_controller( & view );

    EXPECT_EQ( view_controller.GetCurrentFloor(), 1 );
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock( & argc, argv );
    ::testing::InitGoogleTest( & argc, argv );
    return RUN_ALL_TESTS();
}
