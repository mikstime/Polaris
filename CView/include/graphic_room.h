#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include "graphic_item.h"
#include <string>
// TODO временный путь до заголовочных файлов
#include "../Utils/Meta/Meta.h"

namespace Polaris
{
class GraphicRoom : public GraphicItem
{
public:
    explicit GraphicRoom();
    explicit GraphicRoom( const Meta & node, const QRectF & size = QRectF(0, 0, 40, 40 ) );
    GraphicRoom( const GraphicRoom & ) = delete;
    GraphicRoom( const GraphicRoom && ) = delete;
    GraphicRoom & operator = ( const GraphicRoom & ) = delete;
    GraphicRoom & operator = ( const GraphicRoom && ) = delete;

    std::string GetInfo() const;
    void SetColor( const QColor & color ) override;
    void ResetColor() override;
    void SetSelection() override;
    void ResetSelection() override;

private:
    std::string info_;
    QRectF size_;
    QColor color_;

    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
};
} // namespace Polaris



#endif // CGRAPHICS_ITEMS_H
