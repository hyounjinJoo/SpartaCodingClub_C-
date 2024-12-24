#pragma once
#include "HW_01_SimpleProgramming/HW_01_SimpleProgramming.h"
#include "Chapter1-1/Chapter1_1HW.h"
#include "Chapter1-2/Chapter1_2HW.h"
#include "Chapter1-3/Chapter1_3HW.h"
#include "Chapter2-1/Chapter2_1.h"
#include "Chapter2-2/Chapter2_2.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
int main()
{
	int Result = 0;
	//Result = SimpleProgrammingMain();
	//Result = Chapter1_1HWMain();
	//Result = Chapter1_2HWMain();
	//Result = Chapter1_3HWMain();
	//Result = Chapter2_1HWMain();
	Result = Chapter2_2HWMain();

	_CrtDumpMemoryLeaks();
	return Result;
}