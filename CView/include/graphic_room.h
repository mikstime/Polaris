#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include "graphic_item.h"
#include <string>
#include "Meta/Meta.h"

namespace Polaris
{
class GraphicRoom : public GraphicItem
{
public:
    explicit GraphicRoom();
    explicit GraphicRoom( const Meta & node, const QRectF & rect );
    explicit GraphicRoom( const Meta & node, const QSize & size = QSize( 40, 40 ) );
    GraphicRoom( const GraphicRoom & ) = delete;
    GraphicRoom( const GraphicRoom && ) = delete;
    GraphicRoom & operator = ( const GraphicRoom & room );
    GraphicRoom & operator = ( const GraphicRoom && room );

    std::string GetInfo() const;
    void SetColor( const QColor & color ) override;
    void SetSelection() override;
    void ResetSelection() override;

private:
    std::string info_;
    QRectF size_;

    void ResetColor() override;
    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
    QPainterPath shape() const override final;
};
} // namespace Polaris



#endif // CGRAPHICS_ITEMS_H
