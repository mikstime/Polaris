#ifndef MAINAPP_MOCK_GRAPHIC_ITEM_H
#define MAINAPP_MOCK_GRAPHIC_ITEM_H

#include "gmock/gmock.h"
#include "include/graphic_item.h"

using Polaris::GraphicItem;

class MockGraphicItem : public GraphicItem
{
public:
    MOCK_CONST_METHOD0( GetId, size_t() );
    MOCK_CONST_METHOD0( GetFloor, int8_t() );
    MOCK_CONST_METHOD0( GetRole, std::string() );

    MOCK_METHOD3( paint, void( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) );
    MOCK_CONST_METHOD0( boundingRect, QRectF() );
//    QRectF boundingRect() const
//    {
//        return QRectF(-10, -10, 20, 20);
//    }
};

#endif //MAINAPP_MOCK_GRAPHIC_ITEM_H
