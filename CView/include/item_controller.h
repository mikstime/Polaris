#ifndef MAINAPP_ITEM_CONTROLLER_H
#define MAINAPP_ITEM_CONTROLLER_H

#include "include/editor.h"
#include "include/item_collaction.h"
#include <QMouseEvent>

namespace Polaris
{
/**
 *  Контроллер графическоих элементов, при добавлении элементов принимает на себя владение элементами
 */
class ItemController : public QGraphicsScene, public std::enable_shared_from_this< ItemController >
{
public:
    /**
     * @param scene_rect - размер холста
     * @param items_in_controller - структура, сопоставляющая адрес графического элемента в памяти и его айди
     * @param parent - родительский объект
     */
    explicit ItemController( const QRect & scene_rect, std::shared_ptr< ItemCollection > items_in_controller,
                             QObject * parent = nullptr );
    ItemController( const ItemController & ) = delete;
    ItemController( const ItemController && ) = delete;
    ItemController & operator = (const ItemController & ) = delete;
    ItemController & operator = ( const ItemController && ) = delete;
    ~ItemController();

    /**
     * Получить айди первого выделенного помещения
     * @return - айди помещения
     */
    size_t GetCurrentNode() const;

    /**
     * Получить айди второго выделенного помещения
     * @return - айди помещения
     */
    size_t GetPreviousNode() const;

    /**
     * Запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
     * @return - Позиция создаваемого помещения
     */
    QPointF GetMarkDownPos() const;

    /**
     * Получить новую форму
     * @return - полигон формы помещения
     */
    QPolygonF GetNewForm() const;

    /**
     * Инициализировать агрегат Editor, выполняющий редактирование карты
     */
    void InitEditor();

    /**
     * Выделение пути
     * @param cur_path информация о элементах на пути
     */
    virtual void SetCurPath( std::vector< GraphicItem * > & cur_path );

    /**
     * Сбросить редактирование
     */
    void ResetEditing();

    /**
     * Нажатие мыши
     * @param mouse_event - объект, содержащий информацию о нажатии
     */
    virtual void mousePressEvent( QGraphicsSceneMouseEvent * mouse_event ) override;

    /**
     * Мышь отпущена
     * @param mouse_event - объект, содержащий информацию о нажатии
     */
    virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * mouse_event ) override;

    /**
     * Сбросить выбор первого помещения
     */
    void ResetCurrentNode();

    /**
     * Сбросить выбор второго помещения
     */
    void ResetPreviousNode();

    /**
     * Сменить режим работы представления (либо редактирование - true, либо просмотр - false)
     * @param edit - устанавливаемый режим
     * @return - установленный режим
     */
    bool ChangeMode( bool edit );

private:
    bool is_edit_;
    GraphicItem * current_node_;
    GraphicItem * previous_node_;
    std::unique_ptr< Editor > editor_;
    std::shared_ptr< ItemCollection > items_in_controller_;
    std::vector< GraphicItem * > cur_path_;
    bool path_drawn_;


    void SelectCurrentNode(GraphicItem * const new_current );
    void SelectPreviousNode(GraphicItem * const new_previous );
    void ResetPath();
    void RoomPressedLeft(GraphicItem * const cur_item, const QPointF & cur_pos );
    void EmptyPressedLeft(const QPointF & cur_pos );
    void RoomPressedLeftCtrl(GraphicItem * const cur_item, const QPointF & cur_pos );
    void EmptyPressedLeftCtrl(GraphicItem * const cur_item, const QPointF & cur_pos );
    void EmptyPressedRight(const QPointF & cur_pos );
    void RoomReleaseLeft(GraphicItem * const cur_item, const QPointF & cur_pos );
    void EmptyReleaseLeft(const QPointF & cur_pos );
    void RoomReleaseRight(GraphicItem * const cur_item, const QPointF & cur_pos );
    void EmptyReleaseRight(const QPointF & cur_pos );
};
} // namespace Polaris

#endif //MAINAPP_ITEM_CONTROLLER_H