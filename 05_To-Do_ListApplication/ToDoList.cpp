#include "ToDoList.h"
#include <fstream>
#include <iostream>

void ToDoList::addTask(const Task& task) {
    tasks.push_back(task);
}

void ToDoList::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void ToDoList::updateTask(int index, const Task& task) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index] = task;
    }
}

void ToDoList::markTaskCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].setCompleted(true);
    }
}

void ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.getDescription() << "\n" << task.isCompleted() << "\n";
        }
        file.close();
    }
}

void ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        tasks.clear();
        std::string description;
        bool completed;
        while (std::getline(file, description)) {
            file >> completed;
            file.ignore();
            tasks.emplace_back(description, completed);
        }
        file.close();
    }
}

void ToDoList::displayTasks() const {
    for (int i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].getDescription()
                  << (tasks[i].isCompleted() ? " [Completed]" : "") << std::endl;
    }
}
