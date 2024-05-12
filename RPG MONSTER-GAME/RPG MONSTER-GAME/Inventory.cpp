#include "Inventory.h"

Inventory::Inventory(int size) :size(size)
{
	items = new Item* [size]; // ������� ������ ���� ��������� �� Item (Item*) � ���������� ���� ������ � ��������� �� items
}

bool Inventory::add_item(Item_Data Data)     
{
	if (item_count < size) //�������� �� ���������� ����� � ��������� 
	{
		items[item_count] = new Item(Data); //���������� ��������
		item_count++;
		return true;
	}
	return false;
}