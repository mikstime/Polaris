#ifndef MAINAPP_NODE_FORM_H
#define MAINAPP_NODE_FORM_H

#include <QtCore/QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Polaris
{

class NodeForm : public QWidget
{
    Q_OBJECT

public:
    NodeForm();

private:
    QVBoxLayout * main_layout_;

    QHBoxLayout * a_input_layout_;
    QHBoxLayout * b_input_layout_;

    QLabel * a_some_label_;
    QLabel * b_some_label_;

    QLineEdit * a_some_line_edit_;
    QLineEdit * b_some_line_edit_;

    QPushButton * save_button_;

public slots:
    void SaveButtonClick();
};

} // namespace Polaris

#endif //MAINAPP_NODE_FORM_H
