#include "Inventory.h"

Inventory::Inventory(int size) :size(size)
{
	items = new Item* [size]; // создаем массив типа указатель на Item (Item*) и записываем этот массив в указатель на items
}
