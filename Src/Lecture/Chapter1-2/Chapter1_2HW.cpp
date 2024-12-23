#include "../../Common/CommonFunction.h"

#include "Chapter1_2HW.h"

int Run()
{
	Battery NewBattery;
	Print("Initial charge: ", false);
	std::cout << NewBattery.getCharge() << "%\n";

	NewBattery.useBattery();
	NewBattery.useBattery();
	NewBattery.chargeBattery();
	NewBattery.useBattery();

	return 0;
}

int Chapter1_2HWMain()
{
	int Result = Run();

	return Result;
}

Battery::Battery(int initialCharge)
	: charge(0)
	, usingCost(5)
	, chargingPower(7)
{
	charge = initialCharge;
}

void Battery::useBattery()
{
	charge -= usingCost;
	if(0 > charge)
	{
		charge = 0;
	}

	Print("Battery used. Current charge: ", false);
	PrintCurrentCharge();
}

void Battery::chargeBattery()
{
	charge += chargingPower;
	if(100 < charge)
	{
		charge = 100;
	}

	Print("Battery charged. Current charge: ", false);
	PrintCurrentCharge();
}

void Battery::PrintCurrentCharge(bool bNeedENDL) const
{
	std::cout << charge << "%";
	if (bNeedENDL)
	{
		std::cout << "\n";
	}
}
