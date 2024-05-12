#pragma once
#include <string>
using namespace std;
struct Item_Data;
enum item_type {n1, n2};	// ������������� ���
class Item					// ������� �������� (���������� �� �������, ����������� � ��������, ������� ��������� �����)
{
private:
	int item_id;			// ���� �������� ���� || � ������� ������� ������ ���� �������������� id-�����
	string item_name;		// ����� ���������
	item_type type;			// ������ �������������� ����
public:
	Item();
	Item(Item_Data Data);
};
struct Item_Data
{
	int item_id = -1;
	string item_name = "";
	item_type type = n1;
};
