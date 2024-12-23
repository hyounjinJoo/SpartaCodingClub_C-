#include "Chapter2_1.h"
#include "../../Common/CommonFunction.h"


int Chapter2_1HWMain() {
    MyClass obj;
    obj.print();

    PrintENDLs(5);

    unique_ptr<Logger> myLogger = make_unique<Logger>();
    myLogger->logInfo("System is starting.");
    myLogger->logWarning("Low disk space.");
	myLogger->logError("Unable to connect to the server.");
    myLogger->showTotalLogs();

    // 복사 불가능
    //unique_ptr<Logger> testMove = myLogger;
	// main 함수 종료
    return 0;
}

Logger::~Logger()
{
    Print("Logger instance destroyed.");
}

void Logger::logInfo(const std::string& message)
{
    ++logCount;
    Print("[INFO]: ", false);
    Print(message);
}

void Logger::logWarning(const std::string& message)
{
    ++logCount;
    Print("[WARNING]: ", false);
    Print(message);
}

void Logger::logError(const std::string& message)
{
    ++logCount;
    Print("[ERROR]: ", false);
    Print(message);
}

void Logger::showTotalLogs()
{
    std::cout << "Total logs recorded: " << logCount << std::endl;
}
