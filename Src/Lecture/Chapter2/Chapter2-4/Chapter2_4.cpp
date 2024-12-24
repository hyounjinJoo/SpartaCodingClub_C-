#include "Chapter2_4.h"

void Chapter2_4::StudentPrinter::print(Student student)
{
	Print(student.getInfo());
}

Chapter2_4::Student::Student(std::string studentName, int studentAge)
	: name(studentName)
	, age(studentAge)
{
}

std::string Chapter2_4::Student::getInfo()
{
	return "학생 이름: " + name + "\n학생 나이: " + std::to_string(age);
}

void Chapter2_4::MemoryStorage::addTask(Task task)
{
    tasks.push_back(task);
}

void Chapter2_4::DBStorage::addTask(Task task)
{
    Print("DB에 할 일 추가: ", 0);
    Print(task.getDescription());
    tasks.push_back(task);
}

int Chapter2_4_1HWMain()
{
	Chapter2_4::Student student("John Doe", 20);
	Chapter2_4::StudentPrinter printer;

	printer.print(student);

	return 0;
}

int Chapter2_4_2HWMain()
{
    std::cout << "=== MemoryStorage로 작업 ===\n";
    Chapter2_4::MemoryStorage memoryStorage;
    Chapter2_4::TaskManager manager1(&memoryStorage);

    manager1.addTask("C++ 과제 작성하기");
    manager1.addTask("SOLID 원칙 공부하기");

    std::cout << "\n현재 할 일 목록:\n";
    manager1.showTasks();

    manager1.completeTask(1);

    std::cout << "\n업데이트된 할 일 목록:\n";
    manager1.showTasks();

    std::cout << "\n=== DBStorage로 작업 ===\n";
    Chapter2_4::DBStorage dbStorage;
    Chapter2_4::TaskManager manager2(&dbStorage);

    manager2.addTask("DB 작업 테스트");
    manager2.addTask("To-Do 목록 추가");

    std::cout << "\n현재 할 일 목록:\n";
    manager2.showTasks();

    manager2.completeTask(2);

    std::cout << "\n업데이트된 할 일 목록:\n";
    manager2.showTasks();

    return 0;
}