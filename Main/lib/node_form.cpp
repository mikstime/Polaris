#include "include/node_form.h"

Polaris::NodeForm::NodeForm()
{
    a_some_label_ = new QLabel( "Поле 1:" );
    b_some_label_ = new QLabel( "Поле 2:" );

    a_some_line_edit_ = new QLineEdit;
    b_some_line_edit_ = new QLineEdit;

    a_input_layout_ = new QHBoxLayout;
    a_input_layout_->addWidget( a_some_label_ );
    a_input_layout_->addWidget( a_some_line_edit_ );

    b_input_layout_ = new QHBoxLayout;
    b_input_layout_->addWidget( b_some_label_ );
    b_input_layout_->addWidget( b_some_line_edit_ );

    save_button_ = new QPushButton( "Сохранить" );
    connect( save_button_, SIGNAL( clicked() ), this, SLOT( SaveButtonClick() ) );

    main_layout_ = new QVBoxLayout;
    main_layout_->addLayout( a_input_layout_ );
    main_layout_->addLayout( b_input_layout_ );
    main_layout_->addWidget( save_button_ );

    setLayout(main_layout_);

    hide();
}

void Polaris::NodeForm::SaveButtonClick()
{
    this->hide();
}
