#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include "graphic_item.h"
// TODO временный путь до заголовочных файлов
#include "GraphConnection/GraphConnection.h"

namespace Polaris
{
class GraphicConnection : public GraphicItem
{
public:
    explicit GraphicConnection( const QPointF & left, const QPointF & right, const size_t & id, const size_t & floor );
    GraphicConnection( const GraphicConnection & ) = delete;
    GraphicConnection( const GraphicConnection && ) = delete;
    GraphicConnection & operator = ( const GraphicConnection & ) = delete;
    GraphicConnection & operator = ( const GraphicConnection && ) = delete;

    double GetPrice() const;
    void SetColor( const QColor & color ) override;
    void ResetColor() override;
    void SetSelection() override;
    void ResetSelection() override;

private:
    double price_;
    QPointF left_;
    QPointF right_;
    QColor color_;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override final;
    QRectF boundingRect() const override final;
};
} // namespace Polaris

#endif // CGRAPHICS_CONNECTION_H
