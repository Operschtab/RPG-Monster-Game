#pragma once
#include "Item.h"   // ���������� �����
class Inventory		// ���������
{
private:
	int size;		// ������ ������������� �������
	Item** items;	// ������� ��������� �� ������ ���� Item* (��������� �� item)
	//Item*[15];    // �� ������������ �������� ������� ���������� �� Item ���������� int size �� ����

	//�������� ������������� �������
	//int* A;
	// A = new int[size] 
	//Item** = int*
	//Item* = int
public:
	Inventory(int size = 0);	// �����������

};

