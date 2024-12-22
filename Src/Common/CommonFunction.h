#pragma once
#include <iostream>
#include <vector>

constexpr int InitialIntValue = INT_MIN;
constexpr bool SUCCESS = true;
constexpr bool FAIL = false;
constexpr int ASCENDING = 1;
constexpr int DESCENDING = 2;


FORCEINLINE void ClearCMD()
{
	system("cls");
}

FORCEINLINE void ClearCMDWithDelaySec(int DelaySecond = 1)
{
	int SleepLimits = DelaySecond * 10;

	for (int Iter = 0; Iter < SleepLimits; ++Iter)
	{
		Sleep(100);
		std::cout << ".";
	}

	ClearCMD();
}

FORCEINLINE int GetNumberInput()
{
	int Number = InitialIntValue;
	std::cin >> Number;

	return Number;
}

FORCEINLINE void SaveNumberToVector(const int InNumber, std::vector<int>& OutVector)
{
	OutVector.push_back(InNumber);
}

FORCEINLINE void Swap(int& Left, int& Right)
{
	int Temp = Left;
	Left = Right;
	Right = Temp;
}

FORCEINLINE long CalcSumInArray(const std::vector<int>& InVector)
{
	long Value = 0;
	for (int Number : InVector)
	{
		Value += Number;
	}

	return Value;
}

FORCEINLINE double CalcAverageInArray(const std::vector<int>& InVector)
{
	double Value = static_cast<double>(CalcSumInArray(InVector));
	Value /= static_cast<float>(InVector.size());

	return Value;
}

FORCEINLINE void Print(const std::string& InString, bool bUsingEndOfLine = true)
{
	std::cout << InString;
	if (bUsingEndOfLine)
	{
		std::cout << "\n";
	}
}

FORCEINLINE void PrintENDLs(int NumberOfENDL = 1)
{
	for (int Iter = 0; Iter < NumberOfENDL; ++Iter)
	{
		std::cout << "\n";
	}
}

FORCEINLINE void PrintArray(const std::vector<int>& InVector)
{
	std::cout << "¹è¿­ : ";
	for (int Number : InVector)
	{
		std::cout << Number << " ";
	}
	std::cout << "\n";
}

FORCEINLINE void DecideInsertionSortOffset(int& Left, int& Right, const int InOrderingType)
{
	switch (InOrderingType)
	{
	case ASCENDING:
		++Right;
		break;
	case DESCENDING:
		++Left;
		break;
	default:
		break;
	}
}

FORCEINLINE void InsertionSort(std::vector<int>& OutVector, const int InOrderingType = ASCENDING)
{
	int LeftOffset, RightOffset;
	LeftOffset = RightOffset = 0;
	DecideInsertionSortOffset(LeftOffset, RightOffset, InOrderingType);

	int KeyValue = 0;
	bool bNeedSwap = false;
	int CountOfNumbersInArray = static_cast<int>(OutVector.size());
	for (int IDX = 1; IDX < CountOfNumbersInArray; ++IDX)
	{
		KeyValue = OutVector[IDX];
		for (int CompareIDX = IDX - 1; CompareIDX >= 0; --CompareIDX)
		{
			int& LeftNumber = OutVector[CompareIDX + LeftOffset];
			int& RightNumber = OutVector[CompareIDX + RightOffset];

			int& ComparedValue = OutVector[CompareIDX];
			bNeedSwap = false;
			if (ASCENDING == InOrderingType)
			{
				if (ComparedValue <= KeyValue)
				{
					break;
				}

				bNeedSwap = true;
			}
			else if (DESCENDING == InOrderingType)
			{
				if (ComparedValue >= KeyValue)
				{
					break;
				}

				bNeedSwap = true;
			}

			Swap(LeftNumber, RightNumber);
		}
	}
}
