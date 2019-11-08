#include <gtest/gtest.h>
#include "gtest_cview.h"
#include <QApplication>

class tt : public QObject
{
    Q_OBJECT
    tt(QObject *parent) : QObject(parent){}
};

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
