#include "Inventory.h"

Inventory::Inventory(int size) :size(size)
{
	items = new Item* [size]; // ������� ������ ���� ��������� �� Item (Item*) � ���������� ���� ������ � ��������� �� items
}
