#include "include/connection_form.h"

Polaris::ConnectionForm::ConnectionForm( QWidget * button_panel, ModelInterface * model ) :
        button_panel_( button_panel ), model_( model ), first_node_( EMPTY ), second_node_( EMPTY )
{
    // Init price widgets
    auto * price_label = new QLabel( "Стоимость" );
    price_edit_ = new QLineEdit;

    // Creating buttons
    save_button_ = new QPushButton( "Сохранить" );
    connect( save_button_, SIGNAL( clicked() ), this, SLOT( SaveButtonClick() ) );

    cancel_button_ = new QPushButton( "Отменить" );
    connect( cancel_button_, SIGNAL( clicked() ), this, SLOT( CancelButtonClick() ) );

    // Init and set layout
    main_layout_ = new QVBoxLayout;

    main_layout_->addStretch();
    main_layout_->addWidget( price_label );
    main_layout_->addWidget( price_edit_ );
    main_layout_->addWidget( save_button_ );
    main_layout_->addWidget( cancel_button_ );
    main_layout_->addStretch();

    this->setLayout( main_layout_ );

    // Hide self before calling
    this->hide();
}

void Polaris::ConnectionForm::SetNodes( Polaris::Id first_node, Polaris::Id second_node )
{
    first_node_ = first_node;
    second_node_ = second_node;
}

void Polaris::ConnectionForm::SaveButtonClick()
{
    // Getting price
    Price price = price_edit_->text().toDouble();

    GraphConnection new_connection = GraphConnection( first_node_, second_node_, price );
    model_->AddConnection( new_connection );

    this->hide();
    button_panel_->show();
}

void Polaris::ConnectionForm::CancelButtonClick()
{
    this->hide();
    button_panel_->show();
}
