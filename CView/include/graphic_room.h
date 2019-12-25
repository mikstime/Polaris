#ifndef CGRAPHICS_ITEMS_H
#define CGRAPHICS_ITEMS_H

#include "include/graphic_item.h"
#include <string>
#include "Meta/Meta.h"

namespace Polaris
{
/**
 * Графический элемент помещения, является графическим отображением узла графа из модели
 */
class GraphicRoom : public GraphicItem
{
public:
    explicit GraphicRoom();

    /**
     * @param node - информация о помещении из модели
     */
    explicit GraphicRoom( const Meta & node );
    GraphicRoom( const GraphicRoom & ) = delete;
    GraphicRoom( const GraphicRoom && ) = delete;
    GraphicRoom & operator = ( const GraphicRoom & room ) = delete;
    GraphicRoom & operator = ( const GraphicRoom && room ) = delete;
    ~GraphicRoom() = default;

    /**
     * Получить информацию о помещении
     * @return - строка с информацией
     */
    std::string GetInfo() const;

    /**
     * Получить номер помещения
     * @return - строка с номером
     */
    std::string GetRoom() const;

    /**
     * Получить размер соединения
     * @return - полигон, задающий размер
     */
    QPolygonF GetSize() const override;

    /**
     * Установить текущий цвет
     * @param color - цвет
     */
    void SetColor( const QColor & color ) override;

    /**
     * Установить выделение
     */
    void SetSelection() override;

    /**
     * Установить новую информацию о помещении
     * @param nw_meta
     */
    void SetMeta( const Meta & nw_meta );

    /**
     * Сделать достижимым - есть связь (напрямую или через другие помещения) с лестницей
     * @param reach - достижим
     */
    void SetReacheble( bool reach );

    /**
     * Установить картинку для графического элемента
     * @param pic - ссылка на объект картинки
     */
    void SetPic( const QPixmap & pic );

    /**
     * Элемент достижим?
     * @return - достижим
     */
    bool IsReacheble() const;

    /**
     * Сбросить выделение
     */
    void ResetSelection() override;

private:
    std::string info_;
    std::string room_number_;
    QPolygonF size_;
    QPixmap pic_;
    QPointF pic_pos_;
    bool reachebele_;

    void ResetColor() override;
    void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) override final;
    QRectF boundingRect() const override final;
    QPainterPath shape() const override final;

};
} // namespace Polaris



#endif // CGRAPHICS_ITEMS_H