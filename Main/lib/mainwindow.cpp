#include "include/mainwindow.h"

Polaris::MainWindow::MainWindow( GraphController * graph_controller, ModelInterface * model, QWidget * parent) :
        QMainWindow( parent ), model_( model )
{
    setWindowTitle( "Polaris" );

    // Creating button layout
    auto * button_layout_ = new QVBoxLayout;

    // Creating button panel
    button_panel_ = new QWidget;
    button_panel_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Creating NodeForm object
    node_form_ = new NodeForm( button_panel_ );
    node_form_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Creating ConnectionForm object
    auto * connection_form = new ConnectionForm( button_panel_, model );
    connection_form->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Init main layout
    main_layout_ = new QHBoxLayout;
    main_layout_->addWidget( button_panel_ );
    main_layout_->addWidget( node_form_ );
    main_layout_->addWidget( connection_form );

    // Creating window
    auto * window = new QWidget;
    window->setLayout( main_layout_ );

    // Creating View object
    view_ = new GraphicView( this->size(), main_layout_, this );

    Meta a = { 1, "805ю", 120, 120, 2, Role::ROOM };
    view_->AddRoom( a );
    Meta b = { 2, "805ю", 220, 120, 1, Role::ROOM };
    view_->AddRoom( b );
    Meta e = { 3, "805ю", 320, 120, 1, Role::ROOM };
    view_->AddRoom( e );
    GraphConnection c( 3, 2, 10 );
    view_->AddConnection( c );

    // Creating ViewController object
    view_controller_ = new Polaris::ViewController( view_ );

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
    button_click_handler_ = new ButtonClickHandler( node_form_, connection_form, view_controller_, graph_controller, button_panel_ );

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
