#ifndef MAINAPP_GRAPHIC_DOOR_H
#define MAINAPP_GRAPHIC_DOOR_H

#include "graphic_item.h"
#include <vector>

namespace Polaris {
    class GraphicDoor : public GraphicItem {
    public:
        explicit GraphicDoor();
        explicit GraphicDoor( const size_t id, const size_t floor, const QPointF & left, const QPointF & right );
        GraphicDoor(const GraphicDoor & ) = delete;
        GraphicDoor(const GraphicDoor &&) = delete;

        GraphicDoor & operator = (const GraphicDoor & room ) = delete;
        GraphicDoor & operator = (const GraphicDoor && room ) = delete;
        void SetColor( const QColor & color ) override;
        void SetSelection() override;
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
