#include "include/mainwindow.h"

Polaris::MainWindow::MainWindow( ViewController * view_controller, GraphController * graph_controller, QWidget * parent) : QMainWindow(parent)
{
    setWindowTitle( "Polaris" );

    button_layout_ = new QVBoxLayout;

    node_form_ = new NodeForm;

    button_click_handler_ = new ButtonClickHandler( node_form_, view_controller, graph_controller );

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
