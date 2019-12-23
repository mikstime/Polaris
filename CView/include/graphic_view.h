#ifndef CVIEW_H
#define CVIEW_H

#include "include/graph_parser.h"
#include "include/view.h"
#include "include/renderer.h"
#include <QGraphicsView>
#include <QtWidgets/QVBoxLayout>

namespace Polaris
{
/**
 * Фасад
 */
class GraphicView : public View
{
public:
    explicit GraphicView() = default;

    /**
     * @param size - размер холста
     * @param layout - выкладка, на которой располагается холст
     * @param parent - родительский виджет
     */
    explicit GraphicView( const QSize & size, QHBoxLayout * const layout, QWidget * parent );
    GraphicView( const GraphicView & ) = delete;
    GraphicView( const GraphicView && ) = delete;
    GraphicView & operator = (const GraphicView & ) = delete;
    GraphicView & operator = ( const GraphicView && ) = delete;
    ~GraphicView() = default;

    /**
     * Инициализировать карту
     * @param meta - информация о помещениях из модели
     * @param graph - информация о переходах из модели
     */
    void InitMap(const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;

    /**
     * Выделяет помещения на пути
     * @param nodes - помещения
     * @param connections - соединения
     */
    void DrawThePath(const std::vector< Meta > & nodes,
                     const std::vector< GraphConnection > & connections ) override;

    /**
     * Вызывается при изменении информации о помещении в модели
     * @param meta - информация о помещении
     */
    void ChangeRoom(const Meta & meta ) override;

    /**
     * Вызывается при создании помещения в модели
     * @param meta - информация о помещении
     */
    void AddRoom(const Meta & meta ) override;

    /**
     * Вызывается при удалении помещения из модели
     * @param meta - информация о помещении
     */
    void RemoveRoom(const Meta & meta ) override;

    /**
     * Вызывается при создании перехода в модели
     * @param connection - информация о переходе
     */
    void AddConnection(const GraphConnection & connection ) override;

    /**
     * Вызывается при удалении перехода из модели
     * @param connection - информация о переходе
     */
    void RemoveConnection(const GraphConnection & connection ) override;

    /**
     * Переключить на этаж выше
     * @return - переключено
     */
    bool FloorUp() override;

    /**
     * Переключить на этаж нижу
     * @return - переключено
     */
    bool FloorDown() override;

    /**
     * Запрашивает выбранную ноду
     * @return - айди выбранного помещения
     */
    size_t GetSelectedNode() const override;

    /**
     * Запрашивает пару для соединения
     * @return - пара айди выбранных помещений
     */
    std::pair< size_t, size_t > GetSelectedNodes() const override;

    /**
     * Запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
     * @return - Позиция создаваемого помещения
     */
    QPointF GetNodeCoordinates() const override;

    /**
     * Запрашивает текущий этаж
     * @return - Номер этажа
     */
    int8_t GetFloorNumber() const override;

    /**
     * Получить новую форму
     * @return - полигон формы помещения
     */
    QPolygonF GetNewForm() const override;

    /**
     * Задать выкладку
     * @param layout - новая выкладка для расположения холста
     */
    void SetLayout( QHBoxLayout * const layout );

    /**
     * Войти в режим редактирования
     * @param edit - редактирование
     * @return - новый режим редактирование?
     */
    bool ChangeMode( bool edit ) override;

private:
    std::shared_ptr< ItemController > item_controller_;
    std::unique_ptr< GraphParser > graph_parser_;
    std::unique_ptr< Renderer > renderer_;

};
} // namespace Polaris

#endif // CVIEW_H