#ifndef MAINAPP_GRAPHICITEM_H
#define MAINAPP_GRAPHICITEM_H

#include <string>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEllipseItem>

namespace Polaris
{
    class GraphicItem : public QGraphicsItem
    {
    public:
        virtual ~GraphicItem() = default;

        virtual size_t GetId() const = 0 ;
        virtual int8_t GetFloor() const = 0;
        virtual std::string GetRole() const = 0;
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHICITEM_H
