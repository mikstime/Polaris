#include "include/button_click_handler.h"

Polaris::ButtonClickHandler::ButtonClickHandler( NodeForm * form, ViewController * controller )
    : form_( form ), controller_(controller)
{
}

void Polaris::ButtonClickHandler::AddButtonClick()
{
    std::pair< int, int > ids = controller_->GetNodeIds();
    if( ids.first == EMPTY )
    {
        // Ничего не выбрано
        return;
    }
    else if( ids.first != EMPTY && ids.second == EMPTY )
    {
        // Выбрана одна комната
        // TODO: Обращение к GraphController
    }
    else if( ids.first != EMPTY && ids.second != EMPTY )
    {
        // Выбрано две комнаты
        // TODO: Обращение к GraphController
    }
}

void Polaris::ButtonClickHandler::DeleteButtonClick()
{
}

void Polaris::ButtonClickHandler::MoveButtonClick()
{
}

void Polaris::ButtonClickHandler::ChangeButtonClick()
{
    form_->show();
}

void Polaris::ButtonClickHandler::FindRouteButtonClick()
{
}

void Polaris::ButtonClickHandler::FloorUpButtonClick()
{
}

void Polaris::ButtonClickHandler::FloorDownButtonClick()
{
}
