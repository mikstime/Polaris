#include "include/mainwindow.h"

Polaris::MainWindow::MainWindow( GraphController * graph_controller, ModelInterface * model, QWidget * parent) :
        QMainWindow( parent ), model_( model )
{
    setWindowTitle( "Polaris" );

    // Creating button layout
    auto * button_layout_ = new QVBoxLayout;

    // Creating button panel
    button_panel_ = std::make_shared< QWidget >();
    button_panel_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Creating NodeForm object
    node_form_ = std::make_shared< NodeForm >( button_panel_.get() );
    node_form_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Creating ConnectionForm object
    connection_form_ = std::make_shared< ConnectionForm >( button_panel_.get(), model_.get() );
    connection_form_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Init main layout
    auto * main_layout = new QHBoxLayout;
    main_layout->addWidget( button_panel_.get() );
    main_layout->addWidget( node_form_.get() );
    main_layout->addWidget( connection_form_.get() );

    // Creating window
    auto * window = new QWidget;
    window->setLayout( main_layout );

    // Creating View object
    view_ = std::make_shared< GraphicView >( this->size(), main_layout, this );

    // Creating ViewController object
    view_controller_ = std::make_shared< ViewController >( view_.get() );

    // Creating buttons
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
    button_click_handler_ = std::make_shared< ButtonClickHandler >( node_form_.get(), connection_form_.get(), view_controller_.get(), graph_controller, button_panel_.get() );

    ConnectButtons();

    setCentralWidget( window );
}

void Polaris::MainWindow::ConnectButtons()
{
    connect( add_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( AddButtonClick() ) );
    connect( delete_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( DeleteButtonClick() ) );
    connect( move_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( MoveButtonClick() ) );
    connect( change_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( ChangeButtonClick() ) );
    connect( find_route_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( FindRouteButtonClick() ) );
    connect( floor_up_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( FloorUpButtonClick() ) );
    connect( floor_down_button_, SIGNAL( clicked() ), button_click_handler_.get(), SLOT( FloorDownButtonClick() ) );
}
