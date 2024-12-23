#pragma once

#include <iostream>
using namespace std;

int Chapter2_1HWMain();

class MyClass {
private:
    int* ptr;

public:
    // 생성자
    MyClass() {
        ptr = new int(10); // 동적 메모리 할당
        cout << "메모리 할당 완료!" << endl;
    }

    // 소멸자
    ~MyClass() {
        // 추가된 코드, 메모리 누수 방지용
        if(nullptr != ptr)
        {
            delete ptr;
            ptr = nullptr;
        }

    }

    void print() const {
        cout << "값: " << *ptr << endl;
    }
};

class Logger
{
public:
    Logger() : logCount(0) {};
    ~Logger();

    void logInfo(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
    void showTotalLogs();

private:
    int logCount;
};