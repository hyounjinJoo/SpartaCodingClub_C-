#pragma once
#include "CommonFunction.h"

class Animal
{
public:
	virtual void speak() = 0;
};

class Dog : public Animal
{
public:
	virtual void speak() override
	{
		Print("Dog : Wah");
	}
};

class Cat : public Animal
{
public:
	virtual void speak() override
	{
		Print("Cat : Meow");
	}
};

class Pig : public Animal
{
public:
	virtual void speak() override
	{
		Print("Pig : Oink");
	}
};

// 동물의 소리를 출력하는 함수 (수정 금지)
void makeAnimalsSpeak(std::vector<Animal*>& animals);
int Chapter3_1HWMain();