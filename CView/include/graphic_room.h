#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include "graphic_item.h"
// TODO временный путь до заголовочных файлов
#include "../Model/include/Meta/Meta.h"

namespace Polaris
{
class GraphicRoom : public GraphicItem
{
public:
    explicit GraphicRoom( const Meta & node, const QRectF & size );
    GraphicRoom( const GraphicRoom & ) = delete;
    GraphicRoom( const GraphicRoom && ) = delete;
    GraphicRoom & operator = ( const GraphicRoom & ) = delete;
    GraphicRoom & operator = ( const GraphicRoom && ) = delete;

    std::string GetInfo() const;
    size_t GetId() const override;
    int8_t GetFloor() const override;
    std::string GetRole() const override;
private:
    std::string info_;
    QRectF size_;
    size_t id_;
    int8_t floor_;
    std::string role_;

    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
};
} // namespace Polaris



#endif // CGRAPHICS_ITEMS_H
