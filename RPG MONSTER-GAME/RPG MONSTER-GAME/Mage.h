#pragma once
#include "Hero.h"
class Mage final: public Hero   // final прописывается для того, чтобы ускорить работу программы при использовании виртуальных методов
{                               // также final обозначает что мы не сможем создавать дочерние классы этого класса
protected:

public:
	// Mage(int hp, int mp, int power, int agility, int intelligence,int defence, string hero_name);
	Mage(Creature_Data Data, string hero_name);

	void use_skill() override;  // override означает что мы перезаписываем виртуальный метод родительского класса под нужды нашего класса
};

