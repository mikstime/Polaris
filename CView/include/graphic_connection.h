#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include "graphic_item.h"
// TODO временный путь до заголовочных файлов
#include "../Model/include/GraphConnection/GraphConnection.h"

namespace Polaris
{
class GraphicConnection : public GraphicItem
{
public:
    explicit GraphicConnection( const QPointF & left, const QPointF & right, const GraphConnection & connection );
    GraphicConnection( const GraphicConnection & ) = delete;
    GraphicConnection( const GraphicConnection && ) = delete;
    GraphicConnection & operator = ( const GraphicConnection & ) = delete;
    GraphicConnection & operator = ( const GraphicConnection && ) = delete;

    double GetPrice() const;
    size_t GetId() const override;
    int8_t GetFloor() const override;
    std::string GetRole() const override;

private:
    double price_;
    QPointF left_;
    QPointF right_;
    size_t id_;
    int8_t floor_;
    std::string role_;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override final;
    QRectF boundingRect() const override final;
};
} // namespace Polaris

#endif // CGRAPHICS_CONNECTION_H
