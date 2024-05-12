#include "Inventory.h"

Inventory::Inventory(int size) :size(size)
{
	items = new Item* [size]; // создаем массив типа указатель на Item (Item*) и записываем этот массив в указатель на items
}

bool Inventory::add_item(Item_Data Data)     
{
	if (item_count < size) //проверка на оставшеес€ место в инвентаре 
	{
		items[item_count] = new Item(Data); //ƒобавление предмета
		item_count++;
		return true;
	}
	return false;
}