#pragma once
#include "Hero.h"

class Warrior final : public Hero // final ������������� ��� ����, ����� �������� ������ ��������� ��� ������������� ����������� �������
{                                 // ����� final ���������� ��� �� �� ������ ��������� �������� ������ ����� ������
protected:

public:
	// Warrior(int hp, int mp, int power, int agility, int intelligence,int defence, string hero_name);
	Warrior(Creature_Data Data, string hero_name);
	
	void use_skill() override;    // override �������� ��� �� �������������� ����������� ����� ������������� ������ ��� ����� ������ ������ 
};                                // ���������� � � .���

