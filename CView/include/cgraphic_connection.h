#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

struct GraphConnection {}; // структура, соответствующая соединению

namespace Polaris
{
class CGraphicConnection : public QGraphicsLineItem
{
public:
    explicit CGraphicConnection( GraphConnection & connection_info, const QLineF & line,
                                 QGraphicsItem * parent = nullptr );
    size_t GetId();
    double GetPrice();

private:
    size_t id_;
    double price_;

    void mousePressEvent( QMoveEvent * event );
};
} // namespace Polaris

#endif // CGRAPHICS_CONNECTION_H
