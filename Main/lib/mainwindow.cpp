#include "include/mainwindow.h"

Polaris::MainWindow::MainWindow( GraphController * graph_controller, ModelInterface * model, QWidget * parent) :
        QMainWindow( parent ), model_( model )
{
    setWindowTitle( "Polaris" );

    setFixedSize( 1600, 900 );

    auto * main_layout = new QHBoxLayout;

    // Creating View object
    view_ = std::make_shared< GraphicView >( this->size(), main_layout, this );

    // Creating ViewController object
    view_controller_ = std::make_shared< ViewController >( view_.get() );

    // Creating button layout
    auto * button_layout_ = new QVBoxLayout;

    // Creating button panel
    button_panel_ = std::make_shared< QWidget >();
    button_panel_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Creating NodeForm object
    node_form_ = std::make_shared< NodeForm >( button_panel_.get(), model_.get(), view_controller_.get(), graph_controller );
    node_form_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Creating ConnectionForm object
    connection_form_ = std::make_shared< ConnectionForm >( button_panel_.get(), model_.get() );
    connection_form_->setFixedSize( SIDE_PANEL_WIDTH, SIDE_PANEL_HEIGHT );

    // Init main layout
    main_layout->addWidget( button_panel_.get() );
    main_layout->addWidget( node_form_.get() );
    main_layout->addWidget( connection_form_.get() );

    // Creating window
    auto * window = new QWidget;
    window->setLayout( main_layout );

    // Creating ViewSub object
    view_sub_ = std::shared_ptr< ModelSubscriber >( new ViewSub( view_ ) );
    model_->Subscribe( view_sub_ );

    // Creating buttons
    buttons_["add"] = new QPushButton( "Добавить" );
    buttons_["delete"] = new QPushButton( "Удалить" );
    buttons_["change"] = new QPushButton( "Изменить" );
    buttons_["find_route"] = new QPushButton( "Найти маршрут" );
    buttons_["floor_up"] = new QPushButton( "Вверх" );
    buttons_["floor_down"] = new QPushButton( "Вниз" );
    buttons_["change_mode"] = new QPushButton( "Режим редактирования" );
    buttons_["download"] = new QPushButton( "Загрузить" );
    buttons_["save"] = new QPushButton( "Сохранить" );

    // Floor layout
    auto * floor_layout = new QHBoxLayout;

    auto * floor_label = new QLabel( "Этаж: 1" );

    floor_layout->addWidget( buttons_["floor_up"] );
    floor_layout->addWidget( floor_label );
    floor_layout->addWidget( buttons_["floor_down"] );

    button_layout_->addStretch();
    button_layout_->addWidget( buttons_["add"] );
    button_layout_->addWidget( buttons_["delete"] );
    button_layout_->addWidget( buttons_["change"] );
    button_layout_->addWidget( buttons_["find_route"] );
    button_layout_->addWidget( buttons_["change_mode"] );
    button_layout_->addStretch();
    button_layout_->addLayout( floor_layout );
    button_layout_->addStretch();

    button_panel_->setLayout( button_layout_ );

    // Creating ButtonClickHandler object
    button_click_handler_ = std::make_shared< ButtonClickHandler >( node_form_.get(), connection_form_.get(),
            view_controller_.get(), graph_controller, button_panel_.get(), buttons_["change_mode"], floor_label );

    ConnectButtons();

    setCentralWidget( window );
}

void Polaris::MainWindow::ConnectButtons()
{
    connect( buttons_["add"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( AddButtonClick() ) );
    connect( buttons_["delete"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( DeleteButtonClick() ) );
    connect( buttons_["change"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( ChangeButtonClick() ) );
    connect( buttons_["find_route"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( FindRouteButtonClick() ) );
    connect( buttons_["floor_up"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( FloorUpButtonClick() ) );
    connect( buttons_["floor_down"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( FloorDownButtonClick() ) );
    connect( buttons_["change_mode"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( ChangeModeButtonClick() ) );
    connect( buttons_["download"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( DownloadButtonClick() ) );
    connect( buttons_["save"], SIGNAL( clicked() ), button_click_handler_.get(), SLOT( SaveButtonClick() ) );
}
