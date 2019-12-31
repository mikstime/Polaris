#ifndef NODE_FORM_H
#define NODE_FORM_H

#include <QtCore/QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QString>
#include <memory>
#include <cassert>

#include "Meta/Meta.h"
#include "typedefs.h"
#include "include/ModelInterface/ModelInterface.h"
#include "include/view_controller.h"
#include "include/graph_controller.h"

namespace Polaris
{

enum STATUS
{
    SAVE,
    CHANGE
};

class NodeForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param button_panel - pointer to button panel
     * @param model - pointer to Model object
     * @param view_controller - pointer to ViewController object
     * @param graph_controller - pointer to GraphController object
     */
    explicit NodeForm( QWidget * button_panel, ModelInterface * model, ViewController * view_controller, GraphController * graph_controller );
    ~NodeForm();
    NodeForm( const NodeForm & ) = delete;
    NodeForm & operator=( const NodeForm & ) = delete;
    /**
     * Set current node
     * @param id - Node id
     * @param status - Save or change status
     */
    void SetNode( Id id, STATUS status );

private:
    Polaris::Meta ConstructMeta( Id room_id = 0, std::string room_number = "", std::string room_info = "",
            QPointF room_coords = QPointF(), QPolygonF room_form = QPolygonF(), int8_t room_floor_number = 1,
            Role room_role = Role::ROOM );

    /**
     * Pointers to other classes
     */
    std::shared_ptr< QWidget > button_panel_;
    ModelInterface * model_;
    std::shared_ptr< ViewController > view_controller_;
    std::shared_ptr< GraphController > graph_controller_;

    /**
     * Node id
     */
    Id room_id_;

    /**
     * Main layout
     */
    QVBoxLayout * main_layout_;

    /**
     * Inputs
     */
    QLineEdit * room_number_input_;
    QLineEdit * room_info_input_;

    QLabel * height_label_;
    QLineEdit * height_input_;

    std::array< QRadioButton *, ROLE_COUNT > role_buttons_;

    /**
     * Action buttons
     */
    QPushButton * save_button_;
    QPushButton * change_button_;
    QPushButton * cancel_button_;

public slots:
    /**
     * Save button click handler
     */
    void SaveButtonClick();
    /**
     * Change button click handler
     */
    void ChangeButtonCLick();
    /**
     * Cancel button click handler
     */
    void CancelButtonClick();
};

} // namespace Polaris

#endif // NODE_FORM_H
