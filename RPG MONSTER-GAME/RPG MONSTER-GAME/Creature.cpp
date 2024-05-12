#include "Creature.h"


Creature::Creature(Creature_Data Data)    // ������������� ����� ���������� ���������
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

void Creature::take_damage(int damage)   // ���� ������� �������, �� �������� �� ����� -1, ���� ����� �� �������� �� ����� hp- (defence - power)
{                                        // � ���� ������ damage �� �������� �� ������ - atack(Creature& enemy)
										 // ��� ������� ����� ������������� ���������� ���� , ��� �������� �� ����������� ����� ��������� ���!!!!!!!
	srand(time(nullptr));
	if (rand() % 100 < Dodge_chance) {}								// ���� �������� ������, �� �� �� �������� ����
	else
	{
		int TempDefence = is_defence ? Defence * 2 : Defence;		// ���� "��������� ������"(����� ������ ��� ��������� �������) ����� True, �� ��������� ���� ������
																	// ����� ���� False �� ������ �������� ����������.
		hp -= TempDefence >= damage ? 1 : damage - TempDefence;		//���� ����������� Defence >= damage �����, �� �������� 1, ����� �������� (damage - TempDefence)
	}
	if (hp <= 0)						 // �������� �� ��, ��� �� �����
	{
		hp = 0;							 // �� ���� �������� ���������� ���� 0
		is_dead = true;
	}
}
bool Creature::spend_mp(int mp_creature) // ��������� ����
{
	if (mp > mp_creature)                // ���� ������� ����� ���� ����, ��� ����������� ������� ���� ��� ������������� �����, 
	{                                    // �� ��������� �� ����� ����, ���� ����������� �� ����������
		mp -= mp_creature;
		return true;
	}
	else                                 // ����� �� �� ����� ������������ ����� �.�. ���� �� �������
	{
		return false;
	}
}
void Creature::attack(Creature& enemy)   // ����� ��� ����� �����. �������� ������ �� ������ ����� || ��� ������� ����� ������������� ����, ������� ������ �������� ����
										 // (� main() ��� ����� ��������� ��� ��� = monster d(������� �������), d.attack(*hero_ptr)) - ������ d ������� ����� *hero_ptr
{
	srand(time(nullptr));
	if (rand() % 100 < Crit_chance)						  // ���� �� 100 ������� ������ 30 �� ��������� ���� 	// � �������� ��������� ��� ������� ����-���� � ������� ����� �������
	{													  // (� �������� ��������� ��� ������� ����-���� � ������� ����� �������)
		enemy.take_damage(power * Crit_multy);            // �������� � ����� take_damage(int damage) ���� , ������� ���������� �������� ������ ��� ���� ����� ���� �� �����
	}													  // ���� ����� ���� �� ���� �������� �� ��������� ����� � ���� �� �����
	else
	{
		enemy.take_damage(power);						  // ���� �� ����� ���� ������� ������
	}
}
int Creature::get_hp()						 // ���������� ��������
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

void Creature::HP_recover(int HP_to_recover)	// � �������� �������� �������� �� ������� ���� ��������� �������� (�������� ������� ��������������� +10 ��������) 
{
	if ((hp + HP_to_recover) < Max_HP)		    // ���� ���� �����. �������� + ������� ������� �� �������� ����������� ���������� ��������
	{
		hp += HP_to_recover;				    // �� ��������� ��� �������� � ������ ��������
	}
	else
	{
		//hp = Max_HP;
		HP_recover_Max();						// ����� ������ ��������������� �������� �� ����.
	}
}

void Creature::MP_recover(int MP_to_recover)				// � �������� �������� �������� �� ������� ���� ��������� ���� (�������� ������� ��������������� +10 ����)
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

void Creature::HP_recover_Max()								// ������ �������������� ��������
{
	hp = Max_HP;
}

void Creature::MP_recover_Max()								// ������ �������������� ����
{
	mp = Max_MP;
}



