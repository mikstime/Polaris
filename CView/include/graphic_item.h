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

        explicit GraphicItem( const Id & id, const int8_t & floor = 0, const Role & role = Role::MARK );
        virtual ~GraphicItem() = default;

        Id GetId() const;
        int8_t GetFloor() const;
        Role GetRole() const;
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
