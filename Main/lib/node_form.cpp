#include "include/node_form.h"

Polaris::NodeForm::NodeForm( QWidget * button_panel, ModelInterface * model, ViewController * view_controller ) :
        id_( EMPTY ), x_( EMPTY ), y_( EMPTY ), button_panel_( button_panel ), model_( model ), view_controller_( view_controller )
{
    // Input room number input field
    auto * room_number_layout = new QHBoxLayout;

    auto * room_number_label = new QLabel( "Номер комнаты" );
    room_number_input_ = new QLineEdit;

    room_number_layout->addWidget( room_number_label );
    room_number_layout->addWidget( room_number_input_ );

    // Init role radio buttons
    auto * role_layout = new QVBoxLayout;

    auto * role_label = new QLabel( "Тип" );
    role_layout->addWidget( role_label );

    role_buttons_[0] = new QRadioButton( "Тип 1" );
    role_buttons_[1] = new QRadioButton( "Тип 2" );
    role_buttons_[2] = new QRadioButton( "Тип 3" );
    role_buttons_[3] = new QRadioButton( "Тип 4" );
    role_buttons_[4] = new QRadioButton( "Тип 5" );

    role_buttons_[0]->setChecked( true );

    for( int i = 0; i < ROLE_COUNT; ++i )
        role_layout->addWidget( role_buttons_[i] );

    // Init and connect save button
    save_button_ = new QPushButton( "Сохранить" );
    connect( save_button_, SIGNAL( clicked() ), this, SLOT( SaveButtonClick() ) );

    // Init main layout
    main_layout_ = new QVBoxLayout;

    main_layout_->addStretch();
    main_layout_->addLayout( room_number_layout );
    main_layout_->addLayout( role_layout );
    main_layout_->addWidget( save_button_ );
    main_layout_->addStretch();

    setLayout( main_layout_ );
    this->hide();
}

void Polaris::NodeForm::SetCurrentNodeParams( const Polaris::Id & id,
        const Polaris::Coordinate & x, const Polaris::Coordinate & y )
{
    id_ = id;
    x_ = x;
    y_ = y;
}

Polaris::Meta Polaris::NodeForm::ConstructMeta( const std::string & room_number,
        const int8_t & floor, const Polaris::Role & role )
{
    Meta meta;

    // Set meta params
    meta.graph_node_id = id_;
    meta.room_number = room_number;
    meta.x = x_;
    meta.y = y_;
    meta.floor = floor;
    meta.role = role;

    return meta;
}

void Polaris::NodeForm::SaveButtonClick()
{
    std::string room_number = room_number_input_->text().toStdString();
    int floor = view_controller_->GetCurrentFloor();

    Role role = Role::MARK;
    if( role_buttons_[1]->isChecked() )
        role = Role::ROOM;
    else if( role_buttons_[2]->isChecked() )
        role = Role::HALL;
    else if( role_buttons_[3]->isChecked() )
        role = Role::STAIR;
    else if( role_buttons_[4]->isChecked() )
        role = Role::CONNECTION;

    Meta meta = ConstructMeta( room_number, floor, role );

    model_->ChangeMeta( id_, meta );

    // Clearing input field
    room_number_input_->clear();

    // Hide self
    this->hide();
    button_panel_->show();
}
