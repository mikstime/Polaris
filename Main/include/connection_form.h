#ifndef CONNECTION_FORM_H
#define CONNECTION_FORM_H

#include <QtCore/QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include "Meta/Meta.h"
#include "include/graph_controller.h"

namespace Polaris
{

class ConnectionForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param button_panel - Pointer to button panel
     * @param model - Pointer to Model object
     */
    ConnectionForm( QWidget * button_panel, ModelInterface * model );
    /**
     * Set current nodes
     * @param first_node - First node
     * @param second_node - Second node
     */
    void SetNodes( Id first_node, Id second_node );

private:
    Id first_node_, second_node_;

    std::shared_ptr< QWidget > button_panel_;
    std::shared_ptr< ModelInterface > model_;

    // Price input field
    QLineEdit * price_edit_;

    QVBoxLayout * main_layout_;

    QPushButton * save_button_;

public slots:
    /**
     * Save button click handler
     */
    void SaveButtonClick();
};

} // namespace Polaris

#endif // CONNECTION_FORM_H
