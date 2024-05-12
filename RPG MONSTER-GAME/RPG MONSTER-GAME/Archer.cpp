#include "Archer.h"

// Archer::Archer(int hp, int mp, int power, int agility, int intelligence,int defence, string hero_name) :Hero(hp, mp, power, agility, intelligence,defence, hero_name) {}
Archer::Archer(Creature_Data Data, string hero_name): Hero(Data, hero_name) {}

void Archer::use_skill()
{
	cout << "Archer";
}
;
