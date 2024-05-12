#pragma once
#include "Item.h"   // подключили класс
class Inventory		// инвентарь
{
private:
	int size;			 // размер динамического массива
	int item_count = 0;  //
	Item** items;		 // создали указатель на массив типа Item* (указатель на item)
	//Item*[15];		 // не динамическое создание массива указателей на Item переменной int size не надо

	//создание динамического массива
	//int* A;
	// A = new int[size] 
	//Item** = int*
	//Item* = int
public:
	Inventory(int size = 0);	// конструктор
	bool add_item(Item_Data Data);    // метод добавления предмета на основе даты предмета

};

