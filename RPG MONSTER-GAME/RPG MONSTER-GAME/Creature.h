#pragma once
#include <string> // ���������� ������, ��� ���� ����� ����� ������������ ���� � ������ Hero �� ����� ������� ���������� ���� string
#include <iostream>
#include <ctime>
#include "Inventory.h"
using namespace std;
struct Creature_Data;			 // ��������

class Creature
{
protected:
	int hp=0;						// ��������
	int Max_HP = 0;					// ������������ ��������
	int mp=0;						// ����
	int Max_MP = 0;					// ������������ ����
	int power=0;					// ����
	int agilitty =0;				// ��������
	int intelligence=0;				// ���������
	int Defence = 0;				// ������
	int Crit_multy = 0;				// ��������� �����
	int Crit_chance = 0;			// ���� ������������ �����
	int Dodge_chance = 0;			// ���� �������
	int Inventory_size = 0;			// ������ ���������
	bool is_dead = false;
	bool is_defence = false;
	Inventory* inventory = nullptr; // cc���� �� ���������, nullptr - ����� �� ���� ������ ���� �� �� �������� ������
public:
	Creature(Creature_Data Data); // �����������/ � ����������� �������� ������ ��������� ������
	void take_damage(int damage); //�������� �� ����� ��������
	bool spend_mp(int mp);        //��������� ���� ��������;
	void attack(Creature& enemy); // ����� ��� ����� ������� ��������. ��� �� � �������� ��������� �������� ������ �� ������ ���� Creature (�����)
	int get_hp();                 // ���������� ������� �������� (���������� � .cpp)
	int get_mp();				  // ���������� ������� ��������� ���� (���������� � .���)
	int get_isDead();			  // ����� ������������ true ��� false. ���� False, �� ����� �����
	void defence();				  // ����� ��������� is_defence � True
	void stop_defence();		  // ���������� is_defence � False
	void refresh_round();		  // ��� ������ ������ ������ ����� ������ is_defence � false
	void HP_recover(int hp);	  // ������������ ��������
	void MP_recover(int mp);	  // ������������ ����
	void HP_recover_Max();		  // ������ �������������� ��������
	void MP_recover_Max();		  // ������ �������������� ����
};

struct Creature_Data			  // ������� ��������� ��� ������������� ����� (������� ����� ���������� � ���� ����) ��������
{
	int Max_HP = 0;				  // ������������ ��������
	int Max_MP = 0;				  // ���� ����
	int agilitty = 0;		      // ��������
	int power = 0;				  // ����
	int intelligence = 0;	      // ���������
	int Defence = 0;			  // ������
	int Crit_multy = 0;			  // ��������� �����
	int Crit_chance = 0;		  // ���� ������������ �����
	int Dodge_chance = 0;		  // ���� �������
	int Inventory_size = 0;		  // ������ ���������
};
