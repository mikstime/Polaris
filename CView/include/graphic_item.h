#ifndef MAINAPP_GRAPHICITEM_H
#define MAINAPP_GRAPHICITEM_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <string>
#include "typedefs.h"

namespace Polaris
{
/**
 * Базовый графический элемент
 */
class GraphicItem : public QGraphicsItem
{
public:
    GraphicItem();

    /**
     * @param id - айди перехода
     * @param floor - этаж прехода
     * @param role - поль графического элемента, определяет его цвет и реакцию на нажатия
     */
    explicit GraphicItem( const Id & id, const int8_t & floor = 0, const Role & role = Role::MARK );
    virtual ~GraphicItem() = default;

    /**
     * Элемент выделен?
     * @return - выделен
     */
    bool IsSelected() const;

    /**
     * Получить айди элемента
     * @return - айди
     */
    Id GetId() const;

    /**
     * Получить этаж
     * @return - номер этажа
     */
    int8_t GetFloor() const;

    /**
     * Получить роль элемента
     * @return - роль
     */
    Role GetRole() const;

    /**
     * Получить текущий цвет
     * @return - цвет
     */
    QColor GetCurColor() const;

    /**
     * Получить стандартный цвет
     * @return - цвет
     */
    QColor GetDefColor() const;

    /**
     * Получить размер соединения
     * @return - полигон, задающий размер
     */
    virtual QPolygonF GetSize() const { return QPolygonF(); }

    /**
     * Установить стандартный цвет в качетве текущего
     */
    void SetDefaultColor();

    /**
     * Установить стандартный цвет в качетве текущего
     * @param nw_def_color - новый стандартный цвет
     */
    void SetDefaultColor( const QColor & nw_def_color );

    /**
     * Установить текущий цвет
     * @param color - цвет
     */
    virtual void SetColor( const QColor & color ) { return; }

    /**
     * Установить выделение
     */
    virtual void SetSelection() { return; }

    /**
     * Сделать достижимым - есть связь (напрямую или через другие помещения) с лестницей
     * @param reach - достижим
     */
    virtual void SetReachable(bool reach ) { return; }

    /**
     * Установить картинку для графического элемента
     * @param pic - ссылка на объект картинки
     */
    virtual void SetPic( const QPixmap & pic ) { return; }

    /**
     * Элемент достижим?
     * @return - достижим
     */
    virtual bool IsReachable() const { return true; }

    /**
     * Сбросить выделение
     */
    virtual void ResetSelection() { return; }
    QPointF point_pos_;

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