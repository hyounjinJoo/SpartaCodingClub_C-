#pragma once

int Chapter1_3HWMain();

class Adventure
{
public:
	Adventure(){};
	virtual ~Adventure(){};

public:
	virtual void useSkill() = 0;
};

class Warrior final : public Adventure
{
	virtual void useSkill() override;
};
class Mage final : public Adventure
{
	virtual void useSkill() override;
};
class Archer final : public Adventure
{
	virtual void useSkill() override;
};