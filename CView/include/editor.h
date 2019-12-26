#ifndef MAINAPP_EDITOR_H
#define MAINAPP_EDITOR_H

#include "include/graphic_item.h"
#include <memory>
#include <list>
#include <QGraphicsScene>

namespace Polaris
{
/**
 * Знимается редактированием карты: созданием формы нового помещения
 */
class Editor
{

public:
    /**
     * В конструктор передается указатель на сцену, контролирующую графические элементы
     */
    explicit Editor( std::shared_ptr< QGraphicsScene > scene );
    explicit Editor( const Editor & ) = delete;
    explicit Editor( const Editor && ) = delete;
    Editor & operator = (const Editor & ) = delete;
    Editor & operator = ( const Editor && ) = delete;
    ~Editor();

    /**
     * Добавление точек-соединителей на углах заданного помещения
     * @param polygon - форма помещения
     * @param pos - позиция на карте
     */
    void AddConnections( const QPolygonF & polygon, const QPointF & pos );

    /**
     * Добавление точки-соединителя в заданной позиции
     * @param pos - позиция на карте
     */
    void AddConnection( QPointF & pos );

    /**
     * Выбор нажатием точки-соединителя
     * @param item - указатель на объект точки
     */
    void SelectConnection( GraphicItem * const item );

    /**
     * Удаление нажатием точки-соединителя
     * @param item - указатель на объект точки
     */
    void EraseItem( GraphicItem * const item );

    /**
     * Сброс - редактирования
     */
    void ResetEditing();

    /**
     * Получить форму созданного помещения
     * @return - полигон нового помещения
     */
    QPolygon GetNewForm();

    /**
     * Получить позицию создаваемого полигона
     * @return - точка на карте
     */
    QPoint GetPos() const;

private:
    std::shared_ptr< QGraphicsScene > scene_;
    std::list< GraphicItem * > connections_;
    QPolygon selected_;

    /**
     * Проверяет полигон на самопересечение
     * @return полигон валиден?
     */
    bool IsNotValidPolygon();
};
} // namespace Polaris

#endif //MAINAPP_EDITOR_H
