#include "Chapter2_2.h"
#include <iostream>

using namespace std;

//아래 테스트 코드는 변경하지 마세요
int Chapter2_2HWMain() {
    // 정수 더하기
    cout << "3 + 5 = " << add(3, 5) << endl;

    // 실수 더하기
    cout << "2.5 + 4.3 = " << add(2.5, 4.3) << endl;

    // 문자열 합치기
    cout << "\"Hello, \" + \"World!\" = " << add(string("Hello, "), string("World!")) << endl;

    // 아래 코드는 컴파일 에러가 발생해야 함??
    cout << add(true, false) << endl;

    return 0;
}