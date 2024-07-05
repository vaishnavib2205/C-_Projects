#include"Task.h"
using namespace std;

Task::Task(const string& desc, bool comp) : description(desc), completed(comp){
}

void Task::setDescription(const string& desc)
{
    description = desc;
}

string Task::getDescription() const{
    return description;
}

void Task::setCompleted(bool comp)
{
    completed = comp;
}

bool Task::isCompleted() const{
    return completed;
}