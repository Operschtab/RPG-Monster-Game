#pragma once
#include "Item.h"   // ���������� �����
class Inventory		// ���������
{
private:
	int size;			 // ������ ������������� �������
	int item_count = 0;  //
	Item** items;		 // ������� ��������� �� ������ ���� Item* (��������� �� item)
	//Item*[15];		 // �� ������������ �������� ������� ���������� �� Item ���������� int size �� ����

	//�������� ������������� �������
	//int* A;
	// A = new int[size] 
	//Item** = int*
	//Item* = int
public:
	Inventory(int size = 0);	// �����������
	bool add_item(Item_Data Data);    // ����� ���������� �������� �� ������ ���� ��������

};

