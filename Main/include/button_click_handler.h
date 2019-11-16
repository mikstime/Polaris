#ifndef MAINAPP_BUTTON_CLICK_HANDLER_H
#define MAINAPP_BUTTON_CLICK_HANDLER_H

#include <QtCore/QObject>

namespace Polaris
{

class ButtonClickHandler : public QObject
{
    Q_OBJECT

public:
    ButtonClickHandler();

public slots:
    void AddButtonClick();
    void DeleteButtonCLick();
    void MoveButtonClick();
    void ChangeButtonClick();
    void FindRouteButtonCLick();
    void FloorUpButtonClick();
    void FloorDownButtonCLick();
};

} // namespace Polaris

#endif //MAINAPP_BUTTON_CLICK_HANDLER_H
