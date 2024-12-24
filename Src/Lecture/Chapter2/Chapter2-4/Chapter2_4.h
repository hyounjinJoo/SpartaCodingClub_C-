#pragma once

#include "CommonFunction.h"

// 과제 1 클래스
namespace Chapter2_4
{
    class Student;

    class StudentPrinter
    {
    public:
        void print(Student student);
    };

    class Student
    {
    public:
        Student(std::string studentName, int studentAge);

    public:
        const std::string& getName() const { return name; }
        int getAge() const { return age; }
        std::string getInfo();

    private:
        std::string name;
        int age;
    };

    // 과제 2 클래스
    class Task
    {
    public:
        Task(const std::string& string) : description(string) {}

    public:
        void complete() { completed = true; }
        const std::string& getDescription() { return description; }
        bool isCompleted() { return completed; }

    private:
        std::string description;
        bool completed = false;
    };

    class IStorage
    {
    public:
        virtual void addTask(Task task) = 0;
        virtual const std::vector<Task>& getTasks() = 0;
        virtual std::string getStorageType() = 0;
    };

    class MemoryStorage : public IStorage
    {
    public:
        virtual void addTask(Task task) override;
        virtual const std::vector<Task>& getTasks() override { return tasks; };
    	virtual std::string getStorageType() override { return "메모리 저장소"; }

    private:
        std::vector<Task> tasks;
    };

    class DBStorage : public IStorage
    {
    public:
        virtual void addTask(Task task) override;
        virtual const std::vector<Task>& getTasks() override { Print("DB에서 할 일 가져오기");  return tasks; }
        virtual std::string getStorageType() override { return "DB 저장소 (시뮬레이션)"; }

    private:
        std::vector<Task> tasks;
    };


    class TaskManager {
        IStorage* storage;

    public:
        TaskManager(IStorage* s) : storage(s) {}

        // 새로운 할 일 추가
        void addTask(const std::string& description) {
            storage->addTask(Task(description));
        }

        // 현재 할 일 목록 출력
        void showTasks() {
            std::cout << "저장 방식: " << storage->getStorageType() << "\n";
            std::vector<Task> tasks = storage->getTasks();
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].getDescription();
                if (tasks[i].isCompleted()) std::cout << " [완료]";
                std::cout << "\n";
            }
        }

        // 특정 할 일을 완료 처리
        void completeTask(size_t index) {
            std::vector<Task> tasks = storage->getTasks();
            if (index > 0 && index <= tasks.size()) {
                tasks[index - 1].complete();
                storage->addTask(tasks[index - 1]); // 변경된 할 일 저장
            }
            else {
                std::cout << "잘못된 번호입니다.\n";
            }
        }
    };
}


int Chapter2_4_1HWMain();
int Chapter2_4_2HWMain();
