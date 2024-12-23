#pragma once

int Chapter1_2HWMain();
int RunHW01();
int RunHW02();

class Battery
{
public:
	Battery(int initialCharge = 100);
	virtual ~Battery(){};

public:
	int getCharge() const
	{
		return charge;
	}

	void useBattery();
	void chargeBattery();

private:
	void PrintCurrentCharge(bool bNeedENDL = true) const;

private:
	int charge;
	int usingCost;
	int chargingPower;
};

class Fraction
{
public:
	Fraction() : numerator(0), denominator(1) {}
	Fraction(int num, int denom);
	virtual ~Fraction() {};

public:
	int gcd(int a, int b);
	void simplify();
	Fraction multiply(const Fraction& fraction);
	void display();

	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }

	void setNumerator(int num) { numerator = num; }
	void setDenominator(int denom) { denominator = denom; }

private:
	int numerator;
	int denominator;
};