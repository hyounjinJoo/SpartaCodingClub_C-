#pragma once
#include <iostream>
#include <vector>

constexpr int InitialIntValue = INT_MIN;
constexpr bool SUCCESS = true;
constexpr bool FAIL = false;
constexpr int ASCENDING = 1;
constexpr int DESCENDING = 2;


FORCEINLINE void ClearCMD ( )
{
	system ( "cls" );
}

FORCEINLINE void ClearCMDWithDelaySec ( int DelaySecond = 1 )
{
	int SleepLimits = DelaySecond * 10;

	for ( int Iter = 0; Iter < SleepLimits; ++Iter )
	{
		Sleep ( 100 );
		std::cout << ".";
	}

	ClearCMD ( );
}

FORCEINLINE int GetNumberFromInput ( )
{
	int Number = InitialIntValue;
	std::cin >> Number;

	return Number;
}

FORCEINLINE void SaveNumberToArray (const int InNumber, int OutArray[] , int InIDX )
{
	OutArray[ InIDX ] = InNumber;
}

FORCEINLINE void Swap ( int& Left , int& Right )
{
	int Temp = Left;
	Left = Right;
	Right = Temp;
}

FORCEINLINE long CalcSumInArray ( const int InArray[], const int ArraySize )
{
	long Value = 0;
	for (int IDX = 0; IDX < ArraySize; ++IDX)
	{
		Value += InArray[IDX];
	}

	return Value;
}

FORCEINLINE double CalcAverageInArray ( const int InArray[], const int ArraySize )
{
	double Value = static_cast< double >( CalcSumInArray ( InArray, ArraySize ) );
	Value /= static_cast< float >( ArraySize );

	return Value;
}

FORCEINLINE void Print ( const std::string& InString , bool bUsingEndOfLine = true )
{
	std::cout << InString;
	if ( bUsingEndOfLine )
	{
		std::cout << "\n";
	}
}

FORCEINLINE void PrintENDLs ( int NumberOfENDL = 1 )
{
	for ( int Iter = 0; Iter < NumberOfENDL; ++Iter )
	{
		std::cout << "\n";
	}
}

FORCEINLINE void PrintArray ( const int InArray[] , const int InArraySize)
{
	std::cout << "배열 : ";
	for (int IDX = 0; IDX < InArraySize; ++IDX)
	{
		std::cout << InArray[IDX] << " ";
	}
	std::cout << "\n";
}

FORCEINLINE void DecideInsertionSortOffset ( int& Left , int& Right , const int InOrderingType )
{
	switch ( InOrderingType )
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

FORCEINLINE void InsertionSort ( int OutArray[] , int ArraySize, const int InOrderingType = ASCENDING )
{
	int LeftOffset , RightOffset;
	LeftOffset = RightOffset = 0;
	DecideInsertionSortOffset ( LeftOffset , RightOffset , InOrderingType );

	int KeyValue = 0;
	bool bNeedSwap = false;
	for ( int IDX = 1; IDX < ArraySize; ++IDX )
	{
		KeyValue = OutArray[ IDX ];
		for ( int CompareIDX = IDX - 1; CompareIDX >= 0; --CompareIDX )
		{
			int& LeftNumber = OutArray[ CompareIDX + LeftOffset ];
			int& RightNumber = OutArray[ CompareIDX + RightOffset ];

			int& ComparedValue = OutArray[ CompareIDX ];
			bNeedSwap = false;
			if ( ASCENDING == InOrderingType )
			{
				if ( ComparedValue <= KeyValue )
				{
					break;
				}

				bNeedSwap = true;
			}
			else if ( DESCENDING == InOrderingType )
			{
				if ( ComparedValue >= KeyValue )
				{
					break;
				}

				bNeedSwap = true;
			}

			Swap ( LeftNumber , RightNumber );
		}
	}
}