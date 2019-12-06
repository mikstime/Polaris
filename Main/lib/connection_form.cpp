#include "include/connection_form.h"

Polaris::ConnectionForm::ConnectionForm( QWidget * button_panel, ModelInterface * model ) :
        button_panel_( button_panel ), model_( model )
{
    // Init price widgets
    price_label_ = new QLabel( "Стоимость" );
    price_edit_ = new QLineEdit;

    // Creating save button
    save_button_ = new QPushButton( "Сохранить" );

    // Init and set layout
    main_layout_ = new QVBoxLayout;

    main_layout_->addStretch();
    main_layout_->addWidget( price_label_ );
    main_layout_->addWidget( price_edit_ );
    main_layout_->addWidget( save_button_ );
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
}
