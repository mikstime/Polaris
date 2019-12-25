#include "include/node_form.h"

#include <QDebug>
#include <utility>

Polaris::NodeForm::NodeForm( QWidget * button_panel, ModelInterface * model, ViewController * view_controller, GraphController * graph_controller ) :
        button_panel_( button_panel ), model_( model ), view_controller_( view_controller ), graph_controller_( graph_controller )
{
    // Input input fields
    auto * room_number_layout = new QHBoxLayout;
    auto * room_number_label = new QLabel( "Номер комнаты" );
    room_number_input_ = new QLineEdit;

    room_number_layout->addWidget( room_number_label );
    room_number_layout->addWidget( room_number_input_ );

    auto * room_info_layout = new QHBoxLayout;
    auto * room_info_label = new QLabel( "Описание" );
    room_info_input_ = new QLineEdit;

    room_info_layout->addWidget( room_info_label );
    room_info_layout->addWidget( room_info_input_ );

    auto * height_layout = new QHBoxLayout;
    height_label_ = new QLabel("Высота");
    height_input_ = new QLineEdit( "1" );

    height_layout->addWidget(height_label_);
    height_layout->addWidget(height_input_);

    // Init role radio buttons
    auto * role_layout = new QVBoxLayout;

    auto * role_label = new QLabel( "Тип" );
    role_layout->addWidget( role_label );

    role_buttons_[0] = new QRadioButton( "Комната" );
    role_buttons_[1] = new QRadioButton( "Коридор" );
    role_buttons_[2] = new QRadioButton( "Лестница" );

    role_buttons_[0]->setChecked( true );

    for( int i = 0; i < 3; ++i )
        role_layout->addWidget( role_buttons_[i] );

    // Init and connect buttons
    save_button_ = new QPushButton( "Сохранить" );
    connect( save_button_, SIGNAL( clicked() ), this, SLOT( SaveButtonClick() ) );

    change_button_ = new QPushButton( "Изменить" );
    connect( change_button_, SIGNAL( clicked() ), this, SLOT( ChangeButtonCLick() ) );
    change_button_->hide();

    cancel_button_ = new QPushButton( "Отменить" );
    connect( cancel_button_, SIGNAL( clicked() ), this, SLOT( CancelButtonClick() ) );

    // Init main layout
    main_layout_ = new QVBoxLayout;

    main_layout_->addStretch();
    main_layout_->addLayout( room_number_layout );
    main_layout_->addLayout( room_info_layout );
    main_layout_->addLayout( height_layout );
    main_layout_->addLayout( role_layout );
    main_layout_->addWidget( save_button_ );
    main_layout_->addWidget( change_button_ );
    main_layout_->addWidget( cancel_button_ );
    main_layout_->addStretch();

    setLayout( main_layout_ );
    this->hide();
}

Polaris::NodeForm::~NodeForm()
{
    delete main_layout_;

    delete room_number_input_;
    delete room_info_input_;

    delete save_button_;
    delete change_button_;
    delete cancel_button_;
}

void Polaris::NodeForm::SetNode( Id id, STATUS status )
{
    room_id_ = id;

    if( status == STATUS::SAVE )
    {
        save_button_->show();
        change_button_->hide();

        height_label_->show();
        height_input_->show();
    }
    else if( status == STATUS::CHANGE )
    {
        save_button_->hide();
        change_button_->show();

        Meta old_meta = model_->getMeta( room_id_ );
        room_number_input_->setText( QString::fromStdString( old_meta.room_number ) );
        room_info_input_->setText( QString::fromStdString( old_meta.info ) );

        if( old_meta.role == Role::ROOM )
            role_buttons_[0]->setChecked( true );
        else if( old_meta.role == Role::HALL )
            role_buttons_[1]->setChecked( true );
        else if( old_meta.role == Role::STAIR )
            role_buttons_[2]->setChecked( true );

        height_label_->hide();
        height_input_->hide();
    }
    else
        assert( false );
}

Polaris::Meta Polaris::NodeForm::ConstructMeta( Polaris::Id room_id, std::string room_number, std::string room_info,
                                                QPointF room_coords, QPolygonF room_form, int8_t room_floor_number,
                                                Polaris::Role room_role )
{
    Meta meta;

    meta.graph_node_id = room_id;
    meta.room_number = std::move(room_number);
    meta.info = std::move(room_info);
    meta.coordinates = room_coords;
    meta.size = room_form;
    meta.floor = room_floor_number;
    meta.role = room_role;

    return meta;
}

void Polaris::NodeForm::SaveButtonClick()
{
    room_id_ = graph_controller_->AddNode();

    std::string room_number = room_number_input_->text().toStdString();
    std::string room_info = room_info_input_->text().toStdString();

    int8_t room_floor_number = view_controller_->GetFloorNumber();

    Role room_role;
    if( role_buttons_[0]->isChecked() )
        room_role = Role::ROOM;
    else if( role_buttons_[1]->isChecked() )
        room_role = Role::HALL;
    else if( role_buttons_[2]->isChecked() )
        room_role = Role::STAIR;
    else
        assert( false );

    QPolygonF room_form = view_controller_->GetNodeForm();

    QPointF room_coords = view_controller_->GetNodeCoords();

    Meta meta = ConstructMeta( room_id_, room_number, room_info, room_coords, room_form,
            room_floor_number, room_role );

    model_->ChangeMeta( room_id_, meta );

    int height = height_input_->text().toInt();

    if( height > 1 )
    {
        for( int i = 0; i < height - 1; ++i )
        {
            Id prev_room_id = room_id_;
            room_id_ = graph_controller_->AddNode();

            meta.graph_node_id = room_id_;
            meta.floor += 1;
            model_->ChangeMeta( room_id_, meta );

//            int price = 0;
//            if( room_role == Role::STAIR )
//                price = 1;
//            GraphConnection connection = GraphConnection( prev_room_id, room_id_, price );
//            model_->AddConnection( connection );
        }
    }

    this->hide();
    button_panel_->show();
}

void Polaris::NodeForm::ChangeButtonCLick()
{
    Meta meta = model_->getMeta( room_id_ );

    // Set new room number and info
    meta.room_number = room_number_input_->text().toStdString();
    meta.info = room_info_input_->text().toStdString();

    // Set new room role
    if( role_buttons_[0]->isChecked() )
        meta.role = Role::ROOM;
    else if( role_buttons_[1]->isChecked() )
        meta.role = Role::HALL;
    else if( role_buttons_[2]->isChecked() )
        meta.role = Role::STAIR;
    else
        assert( false );

    model_->ChangeMeta( room_id_, meta );

    // Hide self
    this->hide();
    button_panel_->show();
}

void Polaris::NodeForm::CancelButtonClick()
{
    this->hide();
    button_panel_->show();
}
