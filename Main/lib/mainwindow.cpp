#include "include/mainwindow.h"

Polaris::MainWindow::MainWindow( GraphController * graph_controller, QWidget * parent) : QMainWindow(parent)
{
    setWindowTitle( "Polaris" );

    auto * button_layout_ = new QVBoxLayout;

    button_panel_ = new QWidget;
    button_panel_->setFixedSize( 200, 400 );

    node_form_ = new NodeForm( button_panel_ );
    node_form_->setFixedSize( 200, 400 );

    // Init main layout
    main_layout_ = new QHBoxLayout;
    main_layout_->addWidget( button_panel_ );
    main_layout_->addWidget( node_form_ );

    auto * window = new QWidget;
    window->setLayout( main_layout_ );

    // Creating View object
    view_ = new GraphicView( this->size(), main_layout_, this );

    // Creating ViewController object
    view_controller_ = new Polaris::ViewController( view_ );

    add_button_ = new QPushButton( "Добавить" );
    delete_button_ = new QPushButton( "Удалить" );
    move_button_ = new QPushButton( "Переместить" );
    change_button_ = new QPushButton( "Изменить" );
    find_route_button_ = new QPushButton( "Найти маршрут" );
    floor_up_button_ = new QPushButton( "Этаж вверх" );
    floor_down_button_ = new QPushButton( "Этаж вниз" );

    button_layout_->addStretch();
    button_layout_->addWidget( add_button_ );
    button_layout_->addWidget( delete_button_ );
    button_layout_->addWidget( move_button_ );
    button_layout_->addWidget( change_button_ );
    button_layout_->addWidget( find_route_button_ );
    button_layout_->addWidget( floor_up_button_ );
    button_layout_->addWidget( floor_down_button_ );
    button_layout_->addStretch();

    button_panel_->setLayout( button_layout_ );

    // Creating ButtonClickHandler object
    button_click_handler_ = new ButtonClickHandler( node_form_, view_controller_, graph_controller, button_panel_ );

    InitButtons();

    setCentralWidget( window );
}

void Polaris::MainWindow::InitButtons()
{
    connect( add_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( AddButtonClick() ) );
    connect( delete_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( DeleteButtonClick() ) );
    connect( move_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( MoveButtonClick() ) );
    connect( change_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( ChangeButtonClick() ) );
    connect( find_route_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( FindRouteButtonClick() ) );
    connect( floor_up_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( FloorUpButtonClick() ) );
    connect( floor_down_button_, SIGNAL( clicked() ), button_click_handler_, SLOT( FloorDownButtonClick() ) );
}
