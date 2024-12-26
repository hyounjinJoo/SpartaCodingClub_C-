#include "HW_02_OOP_Summary.h"
#include "CommonFunction.h"
#include <random>

void Dog::makeSound()
{
	Print("개 : 머엉");
}

void Cat::makeSound()
{
	Print("고양이 : 미야우");
}

void Cow::makeSound()
{
	Print("소 : 음머어");
}

Zoo::~Zoo()
{
	for(int IDX = 0; IDX < animalCount; ++IDX)
	{
		if(animals[IDX])
		{
			delete animals[IDX];
		}
	}

	delete[] animals;
}

void Zoo::addAnimal(Animal* animal)
{
	// 마지막 인덱스에 동물을 추가한다.
	animals[NextAddIDX++] = animal;

	if (NextAddIDX >= animalCount)
	{
		Animal** NewAnimalArray = new Animal * [animalCount *= 2]();
		for (int IDX = 0; IDX <= NextAddIDX; ++IDX)
		{
			NewAnimalArray[IDX] = animals[IDX];
		}

		delete[] animals;

		animals = NewAnimalArray;
	}
}

void Zoo::performActions()
{
	for(int IDX = 0; IDX < NextAddIDX; ++IDX)
	{
		animals[IDX]->makeSound();
	}
}

Animal* Main::createRandomAnimal()
{
	ESpecies species = static_cast<ESpecies>(rand() % 3);
	Animal* animal = nullptr;
	switch(species)
	{
	case ESpecies::Cat:
		animal = new Cat();
		break;
	case ESpecies::Cow:
		animal = new Cow();
		break;
	case ESpecies::Dog:
		animal = new Dog();
		break;
	case ESpecies::End:
	default:
		break;
	}

	return animal;
}

int Main::HW_02_OOPSummaryMain()
{
	std::unique_ptr<Zoo> zoo = std::make_unique<Zoo>(4);

	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());

	zoo->performActions();

	return 0;
}
