#ifndef NODE_FORM_H
#define NODE_FORM_H

#include <QtCore/QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>

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
    NodeForm( QWidget * button_panel );
    /**
     * Set current node id and coordinates
     * @param id - node id
     * @param x - node x-coordinate
     * @param y - node y-coordinate
     */
    void SetCurrentNodeParams( const Id & id, const Coordinate & x, const Coordinate & y );

private:
    Polaris::Meta ConstructMeta( const std::string & room_number, const int8_t & floor, const Role & role );

    QWidget * button_panel_;

    // Current node constant params
    Id id_;
    Coordinate x_, y_;

    QVBoxLayout * main_layout_;

    // Room number input field
    QLabel * room_number_label_;
    QLineEdit * room_number_input_;

    // Floor number input field
    QLabel * floor_label_;
    QLineEdit * floor_input_;

    // Role radio buttons
    QLabel * role_label_;
    std::array< QRadioButton *, ROLE_COUNT > role_buttons_;

    QPushButton * save_button_;

public slots:
    void SaveButtonClick();
};

} // namespace Polaris

#endif // NODE_FORM_H
