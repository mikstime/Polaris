#ifndef MAINAPP_GRAPHIC_DOOR_H
#define MAINAPP_GRAPHIC_DOOR_H

#include "include/graphic_item.h"

namespace Polaris {
/**
 * Графический элемент двери, является графическим отображением перехода
 */
class GraphicDoor : public GraphicItem
{
public:
    explicit GraphicDoor();

    /**
     * @param id - айди перехода
     * @param floor - этаж прехода
     * @param left - левый край стены, на которой отображается дверь
     * @param right - правый край стены, на которой отображается дверь
     */
    explicit GraphicDoor( const size_t id, const size_t floor, const QPointF & left, const QPointF & right );
    GraphicDoor(const GraphicDoor & ) = delete;
    GraphicDoor(const GraphicDoor &&) = delete;
    GraphicDoor & operator = (const GraphicDoor & room ) = delete;
    GraphicDoor & operator = (const GraphicDoor && room ) = delete;
    ~GraphicDoor() = default;

    /**
     * Установить цвет
     * @param color - новый цвет
     */
    void SetColor( const QColor & color ) override;

    /**
     * Задать выделение
     */
    void SetSelection() override;

    /**
     * Сбросить выделение
     */
    void ResetSelection() override;
private:
    QPointF left_;
    QPointF right_;

    void ResetColor() override;
    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
    QPainterPath shape() const override final;

};
} // namespace Polaris

#endif //MAINAPP_GRAPHIC_DOOR_H
