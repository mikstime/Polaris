#ifndef BUTTON_CLICK_HANDLER_H
#define BUTTON_CLICK_HANDLER_H

#include <QtCore/QObject>
#include "node_form.h"
#include "Controller/include/view_controller.h"
#include "Controller/include/graph_controller.h"

namespace Polaris
{

class ButtonClickHandler : public QObject
{
    Q_OBJECT

public:
    ButtonClickHandler( NodeForm * form, ViewController * controller, GraphController * graph_controller );

private:
    NodeForm * form_;
    ViewController * view_controller_{};
    GraphController * graph_controller_{};

public slots:
    /**
     * Add button click handler
     */
    void AddButtonClick();
    /**
     * Delete button click handler
     */
    void DeleteButtonClick();
    /**
     * Move button click handler
     */
    void MoveButtonClick();
    /**
     * Change button click handler
     */
    void ChangeButtonClick();
    /**
     * Find route click handler
     */
    void FindRouteButtonClick();
    /**
     * Floor up button click handler
     */
    void FloorUpButtonClick();
    /**
     * Floor down button click handler
     */
    void FloorDownButtonClick();
};

} // namespace Polaris

#endif // BUTTON_CLICK_HANDLER_H
