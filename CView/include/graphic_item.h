#ifndef MAINAPP_GRAPHICITEM_H
#define MAINAPP_GRAPHICITEM_H

#include <string>
#include <QGraphicsItem>

namespace Polaris
{
    using std::string;

    class GraphicItem : public QGraphicsItem
    {
    public:
        virtual ~GraphicItem() = 0;

        virtual size_t GetId() const = 0 ;
        virtual int8_t GetFloor() const = 0;
        virtual string GetRole() const = 0;
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHICITEM_H
