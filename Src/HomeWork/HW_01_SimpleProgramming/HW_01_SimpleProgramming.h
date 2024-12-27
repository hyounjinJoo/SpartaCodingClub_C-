#pragma once

#include <limits>
#include <string>
#include <assert.h>
#include <windows.h>

int GetHowManyInputNumbers();
void InputNumbersAndSaveToArray(const int InArray[], const int InArraySize);
int PrintSelectInsertionSortOrdering();
void PrintSumAndAverageValue(const int InArray[], const int InArraySize);

void EssentialFunction(int OutArray[], const int InArraySize);
void ChallengeFunction(int OutArray[], const int InArraySize);

void RepeatChallengeFunction(int OutArray[], const int InArraySize);

int SimpleProgrammingMain();

template<typename T>
T* CreateArray ( int Size )
{
	T* Array = new T[ Size ] ( );

	return Array;
}