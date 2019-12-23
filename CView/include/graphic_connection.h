#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include "include/graphic_item.h"
#include "GraphConnection/GraphConnection.h"

namespace Polaris
{
/**
* Графический элемент точки-соединителя
*/
class GraphicConnection : public GraphicItem
{
public:
    /**
     * @param pos - позиция точки
     */
    explicit GraphicConnection( const QPointF & pos );
    GraphicConnection( const GraphicConnection & ) = delete;
    GraphicConnection( const GraphicConnection && ) = delete;
    GraphicConnection & operator = ( const GraphicConnection & ) = delete;
    GraphicConnection & operator = ( const GraphicConnection && ) = delete;
    ~GraphicConnection();

    /**
     * Установить цвет
     * @param color - новый цвет
     */
    void SetColor( const QColor & color ) override;

    /**
     * Установить выделение
     */
    void SetSelection() override;

    /**
     * Получить размер соединения
     * @return - полигон, задающий размер
     */
    QPolygonF GetSize() const override;

    /**
     * Сбросить выделение
     */
    void ResetSelection() override;

    /**
     * Счетчик выбранных точек
     */
    static size_t connection_number_counter_;
private:
    QRectF size_;
    size_t connection_number_;

    void ResetColor() override;
    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
    QPainterPath shape() const override final;
};
} // namespace Polaris

#endif // CGRAPHICS_CONNECTION_H