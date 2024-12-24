#include "Chapter2_3.h"
#include "CommonFunction.h"

int Chapter2_3HWMain()
{
    // 벡터와 맵 데이터 정의
    std::vector<int> vec = { 10, 20, 30, 40, 50 };
    std::map<std::string, int> mp = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    /*
     * 아래 코드스니펫에 작성된 초기화된 벡터와 맵을
     * 순방향 반복자와 역방향 반복자를 활용해서 출력하는 코드를 작성하세요     *
     */
    // 문제: 아래 부분을 완성하세요
    // 벡터 순회
    {
        Print("[벡터 순회]", 2);

        std::vector<int>::iterator IterBegin = vec.begin();
        std::vector<int>::iterator IterEnd = vec.end();
        std::vector<int>::reverse_iterator IterRBegin = vec.rbegin();
        std::vector<int>::reverse_iterator IterREnd = vec.rend();

        Print("[정방향 반복자 이용]");
        for (; IterBegin != IterEnd; ++IterBegin)
        {
            Print(std::to_string(*IterBegin) + " ", 0);
        }

        PrintENDLs(3);

        Print("[역방향 반복자 이용]");
        for (; IterRBegin != IterREnd; ++IterRBegin)
        {
            Print(std::to_string(*IterRBegin) + " ", 0);
        }
        PrintENDLs(5);
    }
    // 맵 순회
	{
		Print("[맵 순회]", 2);

    	std::map<std::string ,int>::iterator IterBegin = mp.begin();
    	std::map<std::string ,int>::iterator IterEnd = mp.end();
    	std::map<std::string ,int>::reverse_iterator IterRBegin = mp.rbegin();
    	std::map<std::string ,int>::reverse_iterator IterREnd = mp.rend();

    	Print("[정방향 반복자 이용]");
    	for (; IterBegin != IterEnd; ++IterBegin)
    	{
    		Print(IterBegin->first + " " + std::to_string(IterBegin->second));
    	}

    	PrintENDLs(2);

    	Print("[역방향 반복자 이용]");
    	for (; IterRBegin != IterREnd; ++IterRBegin)
    	{
    		Print(IterRBegin->first + " " + std::to_string(IterRBegin->second));
    	}
	}
	return 0;
}