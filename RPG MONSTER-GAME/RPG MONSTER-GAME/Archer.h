#pragma once
#include "Hero.h"
class Archer final : public Hero     // final ������������� ��� ����, ����� �������� ������ ��������� ��� ������������� ����������� �������
{                                    // ����� final ���������� ��� �� �� ������ ��������� �������� ������ ����� ������
protected:

public:
	Archer(Creature_Data Data, string hero_name);

	void use_skill() override;     // override �������� ��� �� �������������� ����������� ����� ������������� ������ ��� ����� ������ ������
};

