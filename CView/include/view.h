#ifndef MAINAPP_VIEW_H
#define MAINAPP_VIEW_H

#include "Meta/Meta.h"
#include "GraphNode/GraphNode.h"
#include "GraphConnection/GraphConnection.h"
#include <memory>
#include <QPoint>
#include <QHBoxLayout>
#define QT_NO_DEBUG_OUTPUT

namespace Polaris
{
/**
 * Интерфейс фасада
 */
class View
{
public:
    virtual ~View() = default;

    /**
     * Инициализировать карту
     * @param meta - информация о помещениях из модели
     * @param graph - информация о переходах из модели
     */
    virtual void InitMap(const std::vector< Meta > & meta,
                         const std::vector< GraphConnection > & graph ) = 0;

    /**
     * Выделяет помещения на пути
     * @param nodes - помещения
     * @param connections - соединения
     */
    virtual void DrawThePath(const std::vector< Meta > & path,
                             const std::vector< GraphConnection > & connections ) = 0;

    /**
     * Вызывается при изменении информации о помещении в модели
     * @param meta - информация о помещении
     */
    virtual void ChangeRoom(const Meta & meta ) = 0;

    /**
     * Вызывается при создании помещения в модели
     * @param meta - информация о помещении
     */
    virtual void AddRoom(const Meta & meta ) = 0;

    /**
     * Вызывается при удалении помещения из модели
     * @param meta - информация о помещении
     */
    virtual void RemoveRoom(const Meta & meta ) = 0;

    /**
     * Вызывается при создании перехода в модели
     * @param connection - информация о переходе
     */
    virtual void AddConnection(const GraphConnection & connection ) = 0;

    /**
     * Вызывается при удалении перехода из модели
     * @param connection - информация о переходе
     */
    virtual void RemoveConnection(const GraphConnection & connection ) = 0;

    /**
     * Переключить на этаж выше
     * @return - переключено
     */
    virtual bool FloorUp() = 0;

    /**
     * Переключить на этаж нижу
     * @return - переключено
     */
    virtual bool FloorDown() = 0;

    /**
     * Запрашивает выбранную ноду
     * @return - айди выбранного помещения
     */
    virtual size_t GetSelectedNode() const = 0;

    /**
     * Запрашивает пару для соединения
     * @return - пара айди выбранных помещений
     */
    virtual std::pair< size_t, size_t > GetSelectedNodes() const = 0;

    /**
     * Запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
     * @return - Позиция создаваемого помещения
     */
    virtual QPointF GetNodeCoordinates() const = 0;

    /**
     * Запрашивает текущий этаж
     * @return - Номер этажа
     */
    virtual int8_t GetFloorNumber() const = 0;

    /**
     * Получить новую форму
     * @return - полигон формы помещения
     */
    virtual QPolygonF GetNewForm() const = 0;

    /**
     * Задать выкладку
     * @param layout - новая выкладка для расположения холста
     */
    virtual void SetLayout( QHBoxLayout * const layout ) = 0;

    /**
     * Войти в режим редактирования
     * @param edit - редактирование
     * @return - новый режим редактирование?
     */
    virtual bool ChangeMode( bool edit ) = 0;
};
} // namespace Polaris

#endif //MAINAPP_VIEW_H