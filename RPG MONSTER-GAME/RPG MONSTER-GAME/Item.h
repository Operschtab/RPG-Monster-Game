#pragma once
#include <string>
using namespace std;
enum item_type {n1, n2};	// перечисляемый тип
class Item					// игровые предметы (выпадающие от монстра, продающиеся в магазине, обьекты инвентаря героя)
{
private:
	int item_id;			// поле обьектов игры || у каждого обьекта должен быть индивидуальный id-номер
	string item_name;		// имена предметов
	item_type type;			// обьект перечисляемого типа
public:
	Item(int item_id = -1, string item_name = "", item_type type = n1);
};

