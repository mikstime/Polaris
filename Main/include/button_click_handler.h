#ifndef MAINAPP_BUTTON_CLICK_HANDLER_H
#define MAINAPP_BUTTON_CLICK_HANDLER_H

#include <QtCore/QObject>
#include "node_form.h"
#include "../../Controller/include/view_controller.h"

namespace Polaris
{

class ButtonClickHandler : public QObject
{
    Q_OBJECT

public:
    ButtonClickHandler( NodeForm * form, ViewController * controller );

private:
    NodeForm * form_;
    ViewController * controller_;

public slots:
    void AddButtonClick();
    void DeleteButtonClick();
    void MoveButtonClick();
    void ChangeButtonClick();
    void FindRouteButtonClick();
    void FloorUpButtonClick();
    void FloorDownButtonClick();
};

} // namespace Polaris

#endif //MAINAPP_BUTTON_CLICK_HANDLER_H
