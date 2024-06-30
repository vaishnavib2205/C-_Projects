#define TODOLIST_H

#include<vector>
#include"Task.h"
using namespace std;


class ToDoList{
private:
    vector<Task> tasks;

public:
void addTask(const Task& task);
void deleteTask(int index);
void updateTask(int index, const Task& task);
void markTaskCompleted(int index);
void saveToFile(const string& filename) const;
void loadFromFile(const string& filename);
void displayTasks() const;

};