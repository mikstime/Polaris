#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include "graphic_item.h"
#include "GraphConnection/GraphConnection.h"

namespace Polaris
{
    class GraphicConnection : public GraphicItem
    {
    public:
        explicit GraphicConnection( const QPointF & left, const QPointF & right, const size_t id,
                                    const size_t floor, const double cost );
        GraphicConnection( const GraphicConnection & ) = delete;
        GraphicConnection( const GraphicConnection && ) = delete;
        GraphicConnection & operator = ( const GraphicConnection & ) = delete;
        GraphicConnection & operator = ( const GraphicConnection && ) = delete;

    void SetColor( const QColor & color ) override;
    void SetSelection() override;
    void ResetSelection() override;

private:
    QPointF left_;
    QPointF right_;
    double cost_;

    void ResetColor() override;
    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
    QPainterPath shape() const override final;
};
} // namespace Polaris

#endif // CGRAPHICS_CONNECTION_H