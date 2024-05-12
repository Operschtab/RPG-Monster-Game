#include "Warrior.h"
using namespace std;
// Warrior::Warrior(int hp, int mp, int power, int agility, int intelligence, int defence, string hero_name) :Hero(hp, mp, power, agility, intelligence, defence, hero_name) {}
Warrior::Warrior(Creature_Data Data, string hero_name) : Hero(Data, hero_name) {}

void Warrior::use_skill()
{
	cout << "Warrior";
	
}
;

