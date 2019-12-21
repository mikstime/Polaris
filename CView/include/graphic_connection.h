#ifndef CGRAPHICS_CONNECTION_H
#define CGRAPHICS_CONNECTION_H

#include "graphic_item.h"
#include "GraphConnection/GraphConnection.h"

namespace Polaris
{
    class GraphicConnection : public GraphicItem
    {
    public:
        explicit GraphicConnection( const QPointF & pos );
        GraphicConnection( const GraphicConnection & ) = delete;
        GraphicConnection( const GraphicConnection && ) = delete;
        GraphicConnection & operator = ( const GraphicConnection & ) = delete;
        GraphicConnection & operator = ( const GraphicConnection && ) = delete;
        ~GraphicConnection();

        void SetColor( const QColor & color ) override;
        void SetSelection() override;
        QPolygonF GetSize() const override;
        void ResetSelection() override;

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