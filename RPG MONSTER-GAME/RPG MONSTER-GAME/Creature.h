#pragma once
#include <string> // подключаем стринг, для того чтобы через пространство имен в классе Hero мы могли создать переменную типа string
#include <iostream>
#include <ctime>
#include "Inventory.h"
using namespace std;
struct Creature_Data;			 // прототип

class Creature
{
protected:
	int hp=0;						// здоровье
	int Max_HP = 0;					// максимальное здоровье
	int mp=0;						// мана
	int Max_MP = 0;					// максимальная мана
	int power=0;					// сила
	int agilitty =0;				// ловкость
	int intelligence=0;				// интеллект
	int Defence = 0;				// защита
	int Crit_multy = 0;				// множитель урона
	int Crit_chance = 0;			// шанс срабатывания крита
	int Dodge_chance = 0;			// шанс уворота
	int Inventory_size = 0;			// размер инвентаря
	bool is_dead = false;
	bool is_defence = false;
	Inventory* inventory = nullptr; // ccылка на инвентарь, nullptr - чтобы не было мусора поеа мы не создадим обьект
public:
	Creature(Creature_Data Data); // конструктор/ в конструктор передали обьект структуры данных
	void take_damage(int damage); //получаем по ебалу прототип
	bool spend_mp(int mp);        //расходуем ману прототип;
	void attack(Creature& enemy); // метод для атаки другого существа. тут мы в качестве аргумента передали ссылку на обьект типа Creature (врага)
	int get_hp();                 // возвращаем текущее здоровье (реализация в .cpp)
	int get_mp();				  // возвращаем текущее состояние маны (реализация в .срр)
	int get_isDead();			  // метод возвращающий true или false. Если False, то герой мертв
	void defence();				  // метод переводит is_defence в True
	void stop_defence();		  // возвращаем is_defence в False
	void refresh_round();		  // при начале нового раунда битвы ставим is_defence в false
	void HP_recover(int hp);	  // восстановить здоровье
	void MP_recover(int mp);	  // восстановить ману
	void HP_recover_Max();		  // полное восстановление здоровья
	void MP_recover_Max();		  // полное восстановление маны
};

struct Creature_Data			  // создали структуру для инициализации полей (которые будут изменяться в ходе игры) существа
{
	int Max_HP = 0;				  // максимальное здоровье
	int Max_MP = 0;				  // макс мана
	int agilitty = 0;		      // ловкость
	int power = 0;				  // сила
	int intelligence = 0;	      // интеллект
	int Defence = 0;			  // защита
	int Crit_multy = 0;			  // множитель урона
	int Crit_chance = 0;		  // шанс срабатывания крита
	int Dodge_chance = 0;		  // шанс уворота
	int Inventory_size = 0;		  // размер инвентаря
};
