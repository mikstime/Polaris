#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

struct Meta {};
struct Graph {};

struct GraphNode {}; // структура, соответсвтующая комнате
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

class CGraphicRoom : public QGraphicsEllipseItem
{
public:
    explicit CGraphicRoom( GraphNode & node_info, const QRectF & rect,
                           QGraphicsItem * parent = nullptr );
    size_t GetId();

private:
    size_t id_;

    void mousePressEvent( QMoveEvent * event );
};
} // namespace Polaris

#endif // CGRAPHICS_ITEMS_H
