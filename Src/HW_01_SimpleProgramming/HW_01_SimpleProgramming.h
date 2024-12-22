#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <assert.h>
#include <windows.h>

int GetHowManyInputNumbers();
void InputNumbersAndSaveToArray(std::vector<int>& OutVector);
int PrintSelectInsertionSortOrdering();
void PrintSumAndAverageValue(const std::vector<int>& InVector);

void EssentialFunction(std::vector<int>& OutVector);
void ChallengeFunction(std::vector<int>& OutVector);

void RepeatChallengeFunction(std::vector<int> OutVector);

int SimpleProgrammingMain();