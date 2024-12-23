#pragma once

int Chapter1_2HWMain();
int Run();

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