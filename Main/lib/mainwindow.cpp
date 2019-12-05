#include "Main/include/mainwindow.h"
#include <vector>
#include <QDebug>

Polaris::MainWindow::MainWindow( ViewController * controller, QWidget * parent) : QMainWindow(parent)
{
    setWindowTitle( "Polaris" );

    button_layout_ = new QVBoxLayout;

    node_form_ = new NodeForm;

    button_click_handler_ = new ButtonClickHandler( node_form_, controller );

    InitButtons();

    button_layout_->addWidget( add_button_ );
    button_layout_->addWidget( delete_button_ );
    button_layout_->addWidget( move_button_ );
    button_layout_->addWidget( change_button_ );
    button_layout_->addWidget( find_route_button_ );
    button_layout_->addWidget( floor_up_button_ );
    button_layout_->addWidget( floor_down_button_ );

    main_layout_ = new QHBoxLayout;
    main_layout_->addLayout( button_layout_ );
    main_layout_->addWidget( node_form_ );

    auto * window = new QWidget;
    window->setLayout( main_layout_ );
    graphic_view_ = new GraphicView( this->size(), main_layout_, this );
//
//    Meta a = { 1, "805ю", 120, 120, 1, Role::ROOM };
//    graphic_view_->AddRoom( a );
//    Meta b = { 2, "805ю", 220, 120, 1, Role::ROOM };
//    graphic_view_->AddRoom( b );
//    Meta e = { 3, "805ю", 320, 120, 1, Role::ROOM };
//    graphic_view_->AddRoom( e );
//    qInfo() << "Connection";
//    GraphConnection c( 4, 1, 2, 10 );
//    graphic_view_->AddConnection( c );

    setCentralWidget( window );
}

Polaris::MainWindow::~MainWindow()
{
}

void Polaris::MainWindow::InitButtons()
{
    add_button_ = new QPushButton( "Добавить" );
    delete_button_ = new QPushButton( "Удалить" );
    move_button_ = new QPushButton( "Переместить" );
    change_button_ = new QPushButton( "Изменить" );
    find_route_button_ = new QPushButton( "Найти маршрут" );
    floor_up_button_ = new QPushButton( "Этаж вверх" );
    floor_down_button_ = new QPushButton( "Этаж вниз" );

    connect( add_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( AddButtonClick() ) );
    connect( delete_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( DeleteButtonClick() ) );
    connect( move_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( MoveButtonClick() ) );
    connect( change_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( ChangeButtonClick() ) );
    connect( find_route_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( FindRouteButtonClick() ) );
    connect( floor_up_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( FloorUpButtonClick() ) );
    connect( floor_down_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( FloorDownButtonClick() ) );
}
