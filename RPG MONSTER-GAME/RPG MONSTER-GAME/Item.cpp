#include "Item.h"
Item::Item() {}

Item::Item(Item_Data Data)
{
	item_id = Data.item_id;
	item_name = Data.item_name;
	type = Data.type;
}
