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
}

void Zoo::addAnimal(Animal* animal)
{
	if (animalCount >= 10)
	{
		Print("[오류] : 동물원에 이미 동물이 많네요!");
		delete animal;
		Print("[알림] : 새로운 동물은...어음...아무튼 좋은 곳으로 갔습니다.");

		return;
	}

	animals[animalCount++] = animal;
	Print("[알림] : 새로운 동물이 동물원에 왔어요! 현재 동물원의 동물 수 : " + std::to_string(animalCount));
}

void Zoo::performActions()
{
	Print("[알림] : 동물들이 웁니다~");
	for(int IDX = 0; IDX < animalCount; ++IDX)
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
	std::unique_ptr<Zoo> zoo = std::make_unique<Zoo>();

	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());
	zoo->addAnimal(createRandomAnimal());

	zoo->performActions();

	return 0;
}
