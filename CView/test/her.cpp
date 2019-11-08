#include <gtest/gtest.h>
#include "her.h"
#include <QApplication>

her::her(QObject *parent) : QObject(parent)
{

}

void her::SetSelectedNodes( int node_id )
{
    return;
};

TEST( ControllerIntegration, ConnectChooseRoom )
{
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
