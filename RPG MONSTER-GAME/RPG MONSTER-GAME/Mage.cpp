#include "Mage.h"
// Mage::Mage(int hp, int mp, int power, int agility, int intelligence,int defence, string hero_name) : Hero(hp, mp, power, agility, intelligence,defence, hero_name) {}
Mage::Mage(Creature_Data Data, string hero_name) : Hero(Data, hero_name) {}
void Mage::use_skill()
{
	cout << "Mage";
}
;
