#include "Creature.h"


Creature::Creature(Creature_Data Data)    // инициализация полей значениями структуры
{
	Max_HP = Data.Max_HP;
	hp = Max_HP;
	Max_MP = Data.Max_MP;
	mp = Max_MP;
	agilitty = Data.agilitty;
	power = Data.power;
	intelligence = Data.intelligence;
	Defence = Data.Defence;
	Crit_multy = Data.Crit_multy;
	Crit_chance = Data.Crit_chance;
	Dodge_chance = Data.Dodge_chance;
}

void Creature::take_damage(int damage)   // если условие истинно, то получаем по ебалу -1, если ложно то получаем по ебалу hp- (defence - power)
{                                        // в этом методе damage мы получает от метода - atack(Creature& enemy)
										 // это главный метод расчитывающий получаемый урон , все операции по получаемому урону создаются тут!!!!!!!
	srand(time(nullptr));
	if (rand() % 100 < Dodge_chance) {}								// если сработал уворот, то мы не получаем урон
	else
	{
		int TempDefence = is_defence ? Defence * 2 : Defence;		// если "Временная защита"(выбор защиты при нападении монстра) равно True, то удваиваем нашу защиту
																	// иначе если False то защита остается неизменной.
		hp -= TempDefence >= damage ? 1 : damage - TempDefence;		//если утверждение Defence >= damage верно, то вычитаем 1, иначе вычитаем (damage - TempDefence)
	}
	if (hp <= 0)						 // проверка на то, жив ли герой
	{
		hp = 0;							 // не даем здоровью опуститься ниже 0
		is_dead = true;
	}
}
bool Creature::spend_mp(int mp_creature) // расходуем ману
{
	if (mp > mp_creature)                // если уровень нашей маны выше, чем необходимый уровень маны для использования магии, 
	{                                    // то списываем из нашей маны, ману затратившую на заклинание
		mp -= mp_creature;
		return true;
	}
	else                                 // иначе мы не можем использовать магию т.к. маны не хватает
	{
		return false;
	}
}
void Creature::attack(Creature& enemy)   // метод для атаки врага. получаем ссылку на обьект врага || это главный метод расчитывающий урон, который должен получить враг
										 // (в main() это будет выглядеть вот так = monster d(создали монстра), d.attack(*hero_ptr)) - монстр d атакует героя *hero_ptr
{
	srand(time(nullptr));
	if (rand() % 100 < Crit_chance)						  // если из 100 выпадет меньше 30 то сработает крит 	// в будующем прописать что нанесен крит-урон и сделать текст красным
	{													  // (в будующем прописать что нанесен крит-урон и сделать текст красным)
		enemy.take_damage(power * Crit_multy);            // передаем в метод take_damage(int damage) силу , которая собственно является уроном для того чтобы дать по ебалу
	}													  // если выпал крит то силу умножаем на множитель крита и бьем по ебалу
	else
	{
		enemy.take_damage(power);						  // крит не выпал бьем обычным ударом
	}
}
int Creature::get_hp()						 // возвращаем здоровье
{	
	return hp;
}
int Creature::get_mp()
{
	return mp;
}
int Creature::get_isDead()
{
	return is_dead;
}
void Creature::defence()
{
	is_defence = true;
}

void Creature::stop_defence()
{
	is_defence = false;
}

void Creature::refresh_round()
{
	stop_defence();
}

void Creature::HP_recover(int HP_to_recover)	// в аргумент передаем значение на которое надо увеличить здоровье (например бутылек восстанавливает +10 здоровья) 
{
	if ((hp + HP_to_recover) < Max_HP)		    // если наше текущ. здоровье + выпитый бутылек не превысит максимально допустимое здоровье
	{
		hp += HP_to_recover;				    // то прибавить это значение к нашему здоровью
	}
	else
	{
		//hp = Max_HP;
		HP_recover_Max();						// иначе просто восстанавливаем здоровье до макс.
	}
}

void Creature::MP_recover(int MP_to_recover)				// в аргумент передаем значение на которое надо увеличить ману (например бутылек восстанавливает +10 маны)
{
	if ((mp + MP_to_recover) < Max_MP)
	{
		mp += MP_to_recover;
	}
	else
	{
		//MP = Max_MP;
		MP_recover_Max();
	}
}

void Creature::HP_recover_Max()								// полное восстановление здоровья
{
	hp = Max_HP;
}

void Creature::MP_recover_Max()								// полное восстановление маны
{
	mp = Max_MP;
}



