#include "Chapter3_1.h"

void makeAnimalsSpeak(std::vector<Animal*>& animals)
{
	for (Animal* animal : animals) {
		animal->speak();
	}
	// 동적으로 할당된 메모리를 해제합니다.
	for (Animal* animal : animals) {
		delete animal;
	}
}

int Chapter3_1HWMain()
{
	std::vector<Animal*> animals;
	animals.push_back(new Dog());
	animals.push_back(new Cat());

	// Bird 객체 추가
	animals.push_back(new Pig());

	makeAnimalsSpeak(animals);
	return 0;
}
