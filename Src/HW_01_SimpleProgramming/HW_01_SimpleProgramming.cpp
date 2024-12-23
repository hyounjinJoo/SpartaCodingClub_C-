#include "HW_01_SimpleProgramming.h"
#include "../Common/CommonFunction.h"

namespace HW_01
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
	int Count = GetNumberFromInput();
	return Count;
}

void InputNumbersAndSaveToArray(int OutArray[], int ArraySize)
{
	Print("[숫자 입력]"); PrintENDLs(2);
	int Number = 0;
	for(int IDX = 0; IDX < ArraySize; ++IDX)
	{
		Print(std::to_string(IDX + 1), false);
		Print("번째 입력 : ", false);

		Number = GetNumberFromInput();
		SaveNumberToArray(Number, OutArray, IDX);
	}
	PrintENDLs(2);
}

void PrintSumAndAverageValue(const int InArray[], const int InArraySize)
{
	long SumValue = CalcSumInArray(InArray, InArraySize);
	double AverageValue = CalcAverageInArray(InArray, InArraySize);

	Print("[필수기능 수행 결과]");	PrintENDLs(2);
	PrintArray(InArray, InArraySize); PrintENDLs(2);
	std::cout << "합계 : " << SumValue << " " << "평균 : " << AverageValue << std::endl; PrintENDLs(2);
}

int PrintSelectInsertionSortOrdering()
{
	Print("정렬 방법을 선택하세요.[1. 오름차순   2. 내림차순]"); PrintENDLs(2);
	Print("정렬 방법 : ", false);
	int OrderingType = GetNumberFromInput();
	PrintENDLs(2);

	return OrderingType;
}

// 필수 기능
void EssentialFunction(int OutArray[], const int InArraySize )
{
	InputNumbersAndSaveToArray ( OutArray , InArraySize );
	PrintSumAndAverageValue(OutArray, InArraySize);
	HW_01::Delay(3);
}

// 도전 기능
void ChallengeFunction(int OutArray[], const int InArraySize )
{
	int OrderingType = PrintSelectInsertionSortOrdering();
	HW_01::Delay(2);

	Print("[정렬 전 상태]"); PrintENDLs();
	PrintArray(OutArray, InArraySize); PrintENDLs();

	InsertionSort(OutArray, InArraySize , OrderingType);

	Print("[정렬 수행 결과]"); PrintENDLs();
	PrintArray(OutArray, InArraySize);
}

// 도전 기능 테스트용 반복 수행
void RepeatChallengeFunction(int OutArray[], const int InArraySize)
{
	int SelectionNumber = 1;
	while(0 != SelectionNumber)
	{
		Print("[정렬 기능 테스트]"); PrintENDLs(2);

		ChallengeFunction(OutArray, InArraySize); PrintENDLs(2);

		Print("테스트를 종료할까요? 종료를 원하시면 0을 입력하세요. : ", false);

		SelectionNumber = GetNumberFromInput();
		HW_01::Delay(0);
	}
}

int SimpleProgrammingMain()
{
	int ArraySize = GetHowManyInputNumbers ( );
	int* Numbers = CreateArray<int> ( ArraySize );
	HW_01::Delay ( 3 );
	EssentialFunction(Numbers, ArraySize);
	RepeatChallengeFunction(Numbers, ArraySize);

	delete[] Numbers;
	return 0;
}