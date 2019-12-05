#ifndef CONNECTION_FORM_H
#define CONNECTION_FORM_H

#include <QtCore/QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include "Meta/Meta.h"

namespace Polaris
{

class ConnectionForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructor
     */
    ConnectionForm();
    /**
     * Set current connection
     * @param id - connection id
     */
    void SetConnection( Id id );

private:
    // Price input field
    QLabel * price_label_;
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
