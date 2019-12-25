#include "include/item_collaction.h"

using Polaris::ItemCollection;
using Polaris::GraphicItem;

ItemCollection::~ItemCollection()
{
    this->EraseItems();
}

void ItemCollection::EraseItems()
{
    id_to_pointer_.erase( id_to_pointer_.begin(), id_to_pointer_.end() );
    pointer_to_id_.erase( pointer_to_id_.begin(), pointer_to_id_.end() );
}

bool ItemCollection::AddItem(GraphicItem * const item, Id id )
{
    GraphicItem * cur_item_ptr = this->FindById( id );
    Id cur_item_id = this->FindByPointer( item );

    if( cur_item_id == 0 && cur_item_ptr == nullptr )
    {
        id_to_pointer_.insert( std::make_pair( id, item ) );
        pointer_to_id_.insert( std::make_pair( item, id ) );
        return true;
    }

    return false;
}

GraphicItem * ItemCollection::FindById(const Id id )
{
    auto cur_item = id_to_pointer_.find( id );

    if( cur_item != id_to_pointer_.end() )
    {
        return cur_item->second;
    }

    return nullptr;
}

Polaris::Id ItemCollection::FindByPointer(GraphicItem * const cur_pointer )
{
    auto cur_item = pointer_to_id_.find( cur_pointer );

    if( cur_item != pointer_to_id_.end() )
    {
        return cur_item->second;
    }

    return 0;
}

GraphicItem * ItemCollection::DeleteItemById(const Id cur_id )
{
    auto cur_item = id_to_pointer_.find( cur_id );

    if( cur_item != id_to_pointer_.end() )
    {
        GraphicItem * pointer = ( * cur_item ).second;
        pointer_to_id_.erase( pointer );
        id_to_pointer_.erase( cur_item );
        return pointer;
    }

    return nullptr;
}