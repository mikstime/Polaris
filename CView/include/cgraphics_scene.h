#ifndef CGRAPHICS_VIEW_H
#define CGRAPHICS_VIEW_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

struct Meta {};
struct Graph {};

struct GraphNode {}; // структура, соответсвтующая комнате
struct GraphConnection {}; // структура, соответствующая соединению

namespace Polaris
{
class CGraphicsScene : public QGraphicsScene
{
public:
    explicit CGraphicsScene( const QRectF & rect, QObject * parent = nullptr );

protected:
    void mousePressEvent( QMoveEvent * event );

};
} // namespace Polaris

#endif // CGRAPHICS_VIEW_H
