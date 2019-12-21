#ifndef BUTTON_CLICK_HANDLER_H
#define BUTTON_CLICK_HANDLER_H

#include <QtCore/QObject>

#include "include/node_form.h"
#include "include/connection_form.h"
#include "include/view_controller.h"
#include "include/graph_controller.h"

namespace Polaris
{

class ButtonClickHandler : public QObject
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param node_form - pointer to NodeForm object
     * @param controller - pointer to ViewController object
     * @param graph_controller - pointer to GraphController object
     * @paran button_panel - pointer to button panel
     */
    ButtonClickHandler( NodeForm * node_form, ConnectionForm * connection_form, ViewController * controller,
            GraphController * graph_controller, QWidget * button_panel, QPushButton * change_mode_button, QLabel * floor_label );

private:
    // Pointers to other objects
    std::shared_ptr< NodeForm > node_form_;
    std::shared_ptr< ConnectionForm > connection_form_;
    std::shared_ptr< QWidget > button_panel_;
    std::shared_ptr< ViewController > view_controller_;
    std::shared_ptr< GraphController > graph_controller_;

    QPushButton * change_mode_button_;
    QLabel * floor_label_;

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
//    void MoveButtonClick();
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
    void ChangeModeButtonClick();
};

} // namespace Polaris

#endif // BUTTON_CLICK_HANDLER_H
