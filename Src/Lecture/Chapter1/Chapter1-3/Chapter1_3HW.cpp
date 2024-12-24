#include "Chapter1_3HW.h"

#include "CommonFunction.h"

int Chapter1_3HWMain()
{
	Adventure* adventure[3];
	adventure[0] = new Warrior();
	adventure[1] = new Mage();
	adventure[2] = new Archer();

	for(int Number = 0; Number < 3; ++Number)
	{
		adventure[Number]->useSkill();
	}

	for (int Number = 0; Number < 3; ++Number)
	{
		delete adventure[Number];
	}

	return 0;
}

void Warrior::useSkill()
{
	Print("Warrior uses Slash!");
}

void Mage::useSkill()
{
	Print("Mage casts Fireball!");
}

void Archer::useSkill()
{
	Print("Archer shoots an Arrow!");
}