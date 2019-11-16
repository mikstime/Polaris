#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include "graphic_item.h"
#include <QStyleOptionGraphicsItem>

struct GraphNode {}; // структура, соответсвтующая комнате

namespace Polaris
{
class GraphicRoom : public GraphicItem
{
public:
    explicit GraphicRoom( const Meta & node, const QRectF & size );
    GraphicRoom( const GraphicRoom & ) = delete;
    GraphicRoom( const GraphicRoom && ) = delete;
    GraphicRoom & operator = ( const GraphicRoom & ) = delete;
    GraphicRoom & operator = ( const GraphicRoom && ) = delete;

    string GetInfo();
    size_t GetId() const override;
    int8_t GetFloor() const override;
    string GetRole() const override;
private:
    string info_;
    QRectF size_;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override final;
    QRectF boundingRect() const override final;
};
} // namespace Polaris



#endif // CGRAPHICS_ITEMS_H
