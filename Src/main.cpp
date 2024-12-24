#pragma once
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// Lecture HomeWork
#include "HW_01_SimpleProgramming/HW_01_SimpleProgramming.h"
#include "Chapter1-1/Chapter1_1HW.h"
#include "Chapter1-2/Chapter1_2HW.h"
#include "Chapter1-3/Chapter1_3HW.h"
#include "Chapter2-1/Chapter2_1.h"
#include "Chapter2-2/Chapter2_2.h"
#include "Chapter2-3/Chapter2_3.h"
#include "Chapter2-4/Chapter2_4.h"
#include "Chapter3-1/Chapter3_1.h"

int main()
{
	int Result = 0;
	//Result = SimpleProgrammingMain();
	//Result = Chapter1_1HWMain();
	//Result = Chapter1_2HWMain();
	//Result = Chapter1_3HWMain();
	//Result = Chapter2_1HWMain();
	//Result = Chapter2_2HWMain();
	//Result = Chapter2_3HWMain();
	//Result = Chapter2_4_1HWMain();
	//Result = Chapter2_4_2HWMain();
	Result = Chapter3_1HWMain();

	_CrtDumpMemoryLeaks();
	return Result;
}