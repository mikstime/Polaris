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
    explicit NodeForm( QWidget * button_panel, ModelInterface * model, ViewController * view_controller );
    void SetNode( Id id, STATUS status );
    void SetNodeCoords( QPointF room_coords );

private:
    Polaris::Meta ConstructMeta( Id room_id = 0, std::string room_number = "", std::string room_info = "",
            QPointF room_coords = QPointF(), QPolygonF room_form = QPolygonF(), int8_t room_floor_number = 1,
            Role room_role = Role::ROOM );

    /**
     * Pointers to other classes
     */
    std::shared_ptr< QWidget > button_panel_;
    std::shared_ptr< ModelInterface > model_;
    std::shared_ptr< ViewController > view_controller_;

    /**
     * Node params
     */
    Id room_id_;
    QPointF room_coords_;

    /**
     * Main layout
     */
    QVBoxLayout * main_layout_;

    /**
     * Inputs
     */
    QLineEdit * room_number_input_;
    QLineEdit * room_info_input_;

    std::array< QRadioButton *, ROLE_COUNT > role_buttons_;

    /**
     * Action buttons
     */
    QPushButton * save_button_;
    QPushButton * change_button_;

public slots:
    void SaveButtonClick();
    void ChangeButtonCLick();
};

} // namespace Polaris

#endif // NODE_FORM_H
