#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include "graphic_item.h"
#include <string>
#include "Meta/Meta.h"
#include <QPolygonF>

namespace Polaris
{
class GraphicRoom : public GraphicItem
{
public:
    explicit GraphicRoom();
    explicit GraphicRoom( const Meta & node );
    GraphicRoom( const GraphicRoom & ) = delete;
    GraphicRoom( const GraphicRoom && ) = delete;
    GraphicRoom & operator = ( const GraphicRoom & room ) = delete;
    GraphicRoom & operator = ( const GraphicRoom && room ) = delete;

    std::string GetInfo() const;
    QPolygonF GetSize() const override;
    void SetColor( const QColor & color ) override;
    void SetSelection() override;
    void SetMeta( const Meta & nw_meta );
    void ResetSelection() override;

private:
    std::string info_;
    QPolygonF size_;

    void ResetColor() override;
    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
    QPainterPath shape() const override final;

};
} // namespace Polaris



#endif // CGRAPHICS_ITEMS_H