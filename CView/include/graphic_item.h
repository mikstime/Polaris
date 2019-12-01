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
        explicit GraphicItem( const size_t & id, const int8_t & floor, const std::string & role );
        virtual ~GraphicItem() = default;

        size_t GetId() const;
        int8_t GetFloor() const;
        std::string GetRole() const;
        virtual void SetColor( const QColor & color ) = 0;
        virtual void ResetColor() = 0;
        virtual void SetSelection() = 0;
        virtual void ResetSelection() = 0;

    private:
        size_t id_;
        int8_t floor_;
        std::string role_;
        // TODO перенести общие поля в родительский класс
    };
} // namespace Polaris

#endif //MAINAPP_GRAPHICITEM_H
