#include "../../Common/CommonFunction.h"

#include "Chapter1_2HW.h"

int RunHW01()
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

int RunHW02()
{
	Fraction f1(1, 2);
	Fraction f2(3, 4);

	f1.multiply(f2).display();

	return 0;
}

int Chapter1_2HWMain()
{
	//int Result = RunHW01();
	int Result = RunHW02();

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

Fraction::Fraction(int num, int denom)
	: numerator(num)
	, denominator(denom)
{
}

int Fraction::gcd(int a, int b)
{
	while(b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

void Fraction::simplify()
{
	int GCD = gcd(denominator, numerator);
	if(1 != GCD)
	{
		denominator /= GCD;
		numerator /= GCD;
	}
}

Fraction Fraction::multiply(const Fraction& fraction)
{
	Fraction newFraction;
	newFraction.setDenominator(denominator * fraction.getDenominator());
	newFraction.setNumerator(numerator * fraction.getNumerator());

	newFraction.simplify();

	return newFraction;
}

void Fraction::display()
{
	Print("출력:");
	Print("곱한 결과: ", false);
	std::cout << numerator << "/" << denominator << "\n";
}
