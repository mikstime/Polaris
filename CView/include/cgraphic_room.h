#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

struct Meta {};
struct Graph {};

struct GraphNode {}; // структура, соответсвтующая комнате

namespace Polaris
{
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
