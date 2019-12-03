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
        explicit GraphicItem( const Id & id, const int8_t & floor, const std::string & role );
        virtual ~GraphicItem() = default;

        Id GetId() const;
        int8_t GetFloor() const;
        std::string GetRole() const;
        virtual void SetColor( const QColor & color ) = 0;
        virtual void ResetColor() = 0;
        virtual void SetSelection() = 0;
        virtual void ResetSelection() = 0;

    private:
        Id id_;
        int8_t floor_;
        std::string role_;
        // TODO перенести общие поля в родительский класс
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHICITEM_H
