#ifndef MAINAPP_GRAPHICITEM_H
#define MAINAPP_GRAPHICITEM_H

#include <string>
#include "typedefs.h"
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEllipseItem>

namespace Polaris
{
    class GraphicItem : public QGraphicsItem
    {
    public:
        GraphicItem();
        explicit GraphicItem( const Id & id, const int8_t & floor = 0, const Role & role = Role::MARK );
        virtual ~GraphicItem() = default;

        bool IsSelected() const;
        Id GetId() const;
        int8_t GetFloor() const;
//        virtual bool OnTheFloor( const int8_t floor ) const;
        Role GetRole() const;
        QColor GetColor() const;
        virtual QPolygonF GetSize() const { return QPolygonF(); };
        void SetDefaultColor();
        virtual void SetColor( const QColor & color ) { return; }
        virtual void SetSelection() { return; }
        virtual void ResetSelection() { return; }

    protected:
        Id id_;
        int8_t floor_;
        Role role_;
        QColor cur_color_;
        QColor def_color_;

        virtual void ResetColor() { return; }
        void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override { return; }
        QRectF boundingRect() const override { return QRectF(); }
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHICITEM_H