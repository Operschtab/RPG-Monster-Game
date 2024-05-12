#pragma once
#include "Hero.h"
class Archer final : public Hero     // final прописывается для того, чтобы ускорить работу программы при использовании виртуальных методов
{                                    // также final обозначает что мы не сможем создавать дочерние классы этого класса
protected:

public:
	Archer(Creature_Data Data, string hero_name);

	void use_skill() override;     // override означает что мы перезаписываем виртуальный метод родительского класса под нужды нашего класса
};

