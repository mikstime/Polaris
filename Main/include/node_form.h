#ifndef NODE_FORM_H
#define NODE_FORM_H

#include <QtCore/QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <memory>

#include "Meta/Meta.h"
#include "typedefs.h"

namespace Polaris
{

class NodeForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param button_panel - pointer to button panel
     */
    explicit NodeForm( QWidget * button_panel );
    /**
     * Set current node id and coordinates
     * @param id - node id
     * @param x - node x-coordinate
     * @param y - node y-coordinate
     */
    void SetCurrentNodeParams( const Id & id, const Coordinate & x, const Coordinate & y );

private:
    Polaris::Meta ConstructMeta( const std::string & room_number, const int8_t & floor, const Role & role );

    std::shared_ptr< QWidget > button_panel_;

    // Current node constant params
    Id id_;
    Coordinate x_, y_;

    QVBoxLayout * main_layout_;

    // Inputs
    QLineEdit * room_number_input_;
    QLineEdit * floor_input_;

    // Role radio buttons
    std::array< QRadioButton *, ROLE_COUNT > role_buttons_;

    QPushButton * save_button_;

public slots:
    void SaveButtonClick();
};

} // namespace Polaris

#endif // NODE_FORM_H
