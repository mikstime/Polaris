#ifndef MAINAPP_ITEM_COLLACTION_H
#define MAINAPP_ITEM_COLLACTION_H

#include "include/graphic_item.h"
#include <memory>
#include "typedefs.h"
#include <unordered_map>

namespace Polaris
{
    class ItemCollaction
    {

    public:
        explicit ItemCollaction() = default;
        explicit ItemCollaction( const ItemCollaction & ) = delete;
        explicit ItemCollaction( const ItemCollaction && ) = delete;
        ItemCollaction & operator = (const ItemCollaction & ) = delete;
        ItemCollaction & operator = ( const ItemCollaction && ) = delete;
        ~ItemCollaction();
        void EraseItems();
        bool AddItem( GraphicItem * const item, Id id );
        GraphicItem * FindById( const Id id );
        Id FindByPointer( GraphicItem * const cur_item );
        GraphicItem * EraseItemById( const Id cur_id );

    private:
        std::unordered_map< Id, GraphicItem * > id_to_pointer_;
        std::unordered_map< GraphicItem *, Id > pointer_to_id_;
    };
} // namespace Polaris

#endif //MAINAPP_ITEM_COLLACTION_H
