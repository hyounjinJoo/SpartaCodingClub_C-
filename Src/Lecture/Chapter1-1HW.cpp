#include "../Common/CommonFunction.h"
#include "Chapter1-1HW.h"

int Chapter1_1HWMain()
{
	int Result = RepeatPrintStars();

	return Result;
}

void PrintStars(int InDesiredSize)
{
	// 상단
	for(int Row = 0; Row < InDesiredSize; ++Row)
	{
		for(int SpaceIDX = 0; SpaceIDX < (InDesiredSize - 1 - Row); ++SpaceIDX)
		{
			std::cout << " ";
		}

		for(int PrintStarIter = 0; PrintStarIter < (2*Row + 1); ++PrintStarIter)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}
	
	// 하단
	for (int Row = 1; Row < InDesiredSize; ++Row)
	{
		for (int SpaceIDX = 0; SpaceIDX < Row; ++SpaceIDX)
		{
			std::cout << " ";
		}

		for (int PrintStarIter = 1; PrintStarIter < (InDesiredSize * 2 - Row * 2); ++PrintStarIter)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}
}

int RepeatPrintStars()
{
	int InputContinue = CONTINUE;
	int DesiredStarSize = 1;
	while(EXIT != InputContinue)
	{
		Print("원하는 별의 크기를 입력해주세요 : ", false);
		DesiredStarSize = GetNumberFromInput();

		PrintStars(DesiredStarSize);

		Print("별 출력을 계속 수행할까요? [아니오 : 0, 예 : 그 외 입력] : ", false);
		InputContinue = GetNumberFromInput();
		ClearCMD();
	}
	return 0;
}