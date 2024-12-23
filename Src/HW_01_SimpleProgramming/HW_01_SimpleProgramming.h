#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <assert.h>
#include <windows.h>

int GetHowManyInputNumbers();
void InputNumbersAndSaveToArray(const int InArray[], const int InArraySize);
int PrintSelectInsertionSortOrdering();
void PrintSumAndAverageValue(const std::vector<int>& InVector);

void EssentialFunction(int OutArray[], const int InArraySize);
void ChallengeFunction(int OutArray[], const int InArraySize);

void RepeatChallengeFunction(std::vector<int> OutVector);

int SimpleProgrammingMain();

template<typename T>
T* CreateArray ( int Size )
{
	T* Array = new T[ Size ] ( );

	return Array;
}