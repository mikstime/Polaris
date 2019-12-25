#ifndef MAINAPP_ITEM_COLLACTION_H
#define MAINAPP_ITEM_COLLACTION_H

#include "include/graphic_item.h"
#include <memory>
#include <unordered_map>
#include "typedefs.h"

namespace Polaris
{
/**
 * Структура, сопоставляющая адрес графического элемента в памяти (используется в качестве идентификатора в Qt) и его айди
 */
struct ItemCollection
{
public:
    explicit ItemCollection() = default;
    explicit ItemCollection(const ItemCollection & ) = delete;
    explicit ItemCollection(const ItemCollection && ) = delete;
    ItemCollection & operator = (const ItemCollection & ) = delete;
    ItemCollection & operator = (const ItemCollection && ) = delete;
    ~ItemCollection();

    /**
     * Удаление всех элементов из структуры (без удаление элементов)
     */
    void EraseItems();

    /**
     * Добавить элемент в структуру
     * @param item - адрес графического элемента
     * @param id - айди графического элемента
     * @return - добавлено
     */
    bool AddItem( GraphicItem * const item, Id id );

    /**
     * Найти адрес элемента по айди
     * @param id - айди графического элемента
     * @return - адрес графического элемента
     */
    GraphicItem * FindById( const Id id );

    /**
     * Найти адрес элемента по адресу в памяти
     * @param cur_item
     * @return
     */
    Id FindByPointer( GraphicItem * const cur_item );

    /**
     * Удалить элемент по айди из структуры (элемент не удаляется)
     * @param cur_id - айди графического элемента
     * @return - адрес графического элемента
     */
    GraphicItem * DeleteItemById( const Id cur_id );

private:
    std::unordered_map< Id, GraphicItem * > id_to_pointer_;
    std::unordered_map< GraphicItem *, Id > pointer_to_id_;
};
} // namespace Polaris

#endif //MAINAPP_ITEM_COLLACTION_H
