#pragma once

class Animal
{
public:
	virtual void makeSound() = 0;
};

enum class ESpecies
{
	Dog = 0,
	Cat,
	Cow,
	End,
};

class Dog : public Animal
{
public:
	virtual void makeSound() override;
};

class Cat : public Animal
{
public:
	virtual void makeSound() override;
};

class Cow : public Animal
{
public:
	virtual void makeSound() override;
};

class Zoo
{
public:
	Zoo() : animalCount(0) {}
	~Zoo();

public:
	void addAnimal(Animal* animal);
	void performActions();

private:
	Animal* animals[10];
	int animalCount;
};

class Main
{
private:
	static Animal* createRandomAnimal();

public:
	static int HW_02_OOPSummaryMain();
};