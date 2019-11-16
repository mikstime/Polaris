#ifndef MAINAPP_NODE_FORM_H
#define MAINAPP_NODE_FORM_H

#include <QtCore/QObject>
#include <QPushButton>

namespace Polaris
{

class NodeForm : public QObject
{
    Q_OBJECT

public:
    NodeForm();

private:
    QPushButton * save_button_;

public slots:
    void SaveButtonClick();
};

} // namespace Polaris

#endif //MAINAPP_NODE_FORM_H
