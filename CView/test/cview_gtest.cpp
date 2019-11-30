#include <gtest/gtest.h>
#include <memory>
#include <QApplication>
#include <QObject>
#include "../include/cview.h"

using Polaris::CGraphicsView;
using std::shared_ptr;

struct GraphNode {};
struct GraphConnection {};

class MockController : public QObject
{
    Q_OBJECT
 public slots:
    void SetSelectedNodes( int node_id ) {}
    void SetSelectedConnection( int connection_id ) {}
    void SaveChangedData( GraphNode node ) {}
    void SaveConnection( GraphConnection connection ) {}
};

TEST( ControllerIntegration, ConnectChooseRoom )
{
    std::shared_ptr< MockController > mock_controller( new MockController );
    std::shared_ptr< CGraphicsView > graphics_view( new CGraphicsView( nullptr ) );

    ASSERT_TRUE( QObject::connect( graphics_view.get(), SIGNAL( ChooseRoom( int ) ),
                                   graphics_view.get(), SLOT( CreateNewConnection() ) ) );
}

TEST( ControllerIntegration, ConnectChooseConnection )
{
    std::shared_ptr< MockController > mock_controller( new MockController );
    std::shared_ptr< CGraphicsView > graphics_view( new CGraphicsView( nullptr ) );

    ASSERT_TRUE( QObject::connect( graphics_view.get(), SIGNAL( ChooseConnection( int ) ),
                                   mock_controller.get(), SLOT( SetSelectedConnection( int ) ) ) );
}

TEST( ControllerIntegration, ConnectSaveChangeData )
{
    std::shared_ptr< MockController > mock_controller( new MockController );
    std::shared_ptr< CGraphicsView > graphics_view( new CGraphicsView( nullptr ) );

    ASSERT_TRUE( QObject::connect( graphics_view.get(), SIGNAL( ChooseRoom( GraphNode ) ),
                                   mock_controller.get(), SLOT( SaveChangedData( GraphNode ) ) ) );
}

TEST( ControllerIntegration, ConnectSaveConnection )
{
    std::shared_ptr< MockController > mock_controller( new MockController );
    std::shared_ptr< CGraphicsView > graphics_view( new CGraphicsView( nullptr ) );

    ASSERT_TRUE( QObject::connect( graphics_view.get(), SIGNAL( ChooseRoom( GraphConnection ) ),
                                   mock_controller.get(), SLOT( SaveConnection( GraphConnection ) ) ) );
}

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
