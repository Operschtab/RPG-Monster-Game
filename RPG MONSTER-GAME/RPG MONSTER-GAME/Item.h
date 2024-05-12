#pragma once
#include <string>
using namespace std;
enum item_type {n1, n2};	// ������������� ���
class Item					// ������� �������� (���������� �� �������, ����������� � ��������, ������� ��������� �����)
{
private:
	int item_id;			// ���� �������� ���� || � ������� ������� ������ ���� �������������� id-�����
	string item_name;		// ����� ���������
	item_type type;			// ������ �������������� ����
public:
	Item(int item_id = -1, string item_name = "", item_type type = n1);
};

