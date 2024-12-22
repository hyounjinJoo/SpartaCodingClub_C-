#include "HW_01_SimpleProgramming.h"
#include "../Common/CommonFunction.h"

namespace Day6
{
	FORCEINLINE void Delay(const int Seconds = 1)
	{
		ClearCMDWithDelaySec(Seconds);
	}
}

int GetHowManyInputNumbers()
{
	Print("[배열 크기 결정]"); PrintENDLs(2);
	Print("숫자를 몇 개 입력하실 지 결정하세요 : ", false);
	int Count = GetNumberInput();
	return Count;
}

void InputNumbersAndSaveToArray(std::vector<int>& OutVector)
{
	int CountOfNumberInArray = GetHowManyInputNumbers(); PrintENDLs(2);
	Day6::Delay();

	Print("[숫자 입력]"); PrintENDLs(2);
	int Number = 0;
	for(int IterCount = 0; IterCount < CountOfNumberInArray; ++IterCount)
	{
		Print(std::to_string(IterCount + 1), false);
		Print("번째 입력 : ", false);

		Number = GetNumberInput();
		SaveNumberToVector(Number, OutVector);
	}
	PrintENDLs(2);
}

void PrintSumAndAverageValue(const std::vector<int>& InVector)
{
	long SumValue = CalcSumInArray(InVector);
	double AverageValue = CalcAverageInArray(InVector);

	Print("[필수기능 수행 결과]");	PrintENDLs(2);
	PrintArray(InVector); PrintENDLs(2);
	std::cout << "합계 : " << SumValue << " " << "평균 : " << AverageValue << std::endl; PrintENDLs(2);
}

int PrintSelectInsertionSortOrdering()
{
	Print("정렬 방법을 선택하세요.[1. 오름차순   2. 내림차순]"); PrintENDLs(2);
	Print("정렬 방법 : ", false);
	int OrderingType = GetNumberInput();
	PrintENDLs(2);

	return OrderingType;
}

// 필수 기능
void EssentialFunction(std::vector<int>& OutVector)
{
	InputNumbersAndSaveToArray(OutVector);
	Day6::Delay(3);
	PrintSumAndAverageValue(OutVector);
	Day6::Delay(3);
}

// 도전 기능
void ChallengeFunction(std::vector<int>& OutVector)
{
	int OrderingType = PrintSelectInsertionSortOrdering();
	Day6::Delay(2);

	Print("[정렬 전 상태]"); PrintENDLs();
	PrintArray(OutVector); PrintENDLs();

	InsertionSort(OutVector, OrderingType);

	Print("[정렬 수행 결과]"); PrintENDLs();
	PrintArray(OutVector);
}

// 도전 기능 테스트용 반복 수행
void RepeatChallengeFunction(std::vector<int> OutVector)
{
	int SelectionNumber = 1;
	while(0 != SelectionNumber)
	{
		Print("[정렬 기능 테스트]"); PrintENDLs(2);

		ChallengeFunction(OutVector); PrintENDLs(2);

		Print("테스트를 종료할까요? 종료를 원하시면 0을 입력하세요. : ", false);

		SelectionNumber = GetNumberInput();
		Day6::Delay(0);
	}
}

int SimpleProgrammingMain()
{
	std::vector<int> Numbers;
	EssentialFunction(Numbers);
	RepeatChallengeFunction(Numbers);

	return 0;
}