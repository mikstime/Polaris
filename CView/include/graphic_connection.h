#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include "graphic_item.h"
#include <QGraphicsScene>
#include <QGraphicsView>

struct GraphConnection {}; // структура, соответствующая соединению

namespace Polaris
{
class GraphicConnection : public GraphicItem
{
public:
    explicit GraphicConnection( const QPointF & left, const QPointF & right );
    GraphicConnection( const GraphicConnection & ) = delete;
    GraphicConnection( const GraphicConnection && ) = delete;
    GraphicConnection & operator = ( const GraphicConnection & ) = delete;
    GraphicConnection & operator = ( const GraphicConnection && ) = delete;

    double GetPrice() const;
    size_t GetId() const override;
    int8_t GetFloor() const override;
    string GetRole() const override;

private:
    double price_;
    QPointF left_;
    QPointF right_;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override final;
    QRectF boundingRect() const override final;
};
} // namespace Polaris

#endif // CGRAPHICS_CONNECTION_H
