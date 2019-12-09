#ifndef MAINAPP_GRAPHIC_POLYGON_H
#define MAINAPP_GRAPHIC_POLYGON_H

#include "graphic_item.h"
#include <vector>

namespace Polaris {
    class GraphicPolygon : public GraphicItem {
    public:
        explicit GraphicPolygon();

        explicit GraphicPolygon(const std::vector<QPointF> &points);

        GraphicPolygon(const GraphicPolygon &) = delete;

        GraphicPolygon(const GraphicPolygon &&) = delete;

        GraphicPolygon &operator=(const GraphicPolygon &room);

        GraphicPolygon &operator=(const GraphicPolygon &&room);

        void SetColor(const QColor &color) override;

        void SetSelection() override;

        void ResetSelection() override;

    private:
        std::vector<QPointF> form_;

        void ResetColor() override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override final;

        QRectF boundingRect() const override final;

        QPainterPath shape() const override final;

    };
} // namespace Polaris

#endif //MAINAPP_GRAPHIC_POLYGON_H
