#pragma once
#include "Hero.h"
class Mage final: public Hero   // final ������������� ��� ����, ����� �������� ������ ��������� ��� ������������� ����������� �������
{                               // ����� final ���������� ��� �� �� ������ ��������� �������� ������ ����� ������
protected:

public:
	// Mage(int hp, int mp, int power, int agility, int intelligence,int defence, string hero_name);
	Mage(Creature_Data Data, string hero_name);

	void use_skill() override;  // override �������� ��� �� �������������� ����������� ����� ������������� ������ ��� ����� ������ ������
};

