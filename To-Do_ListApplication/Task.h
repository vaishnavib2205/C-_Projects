#define TASK_H
#include<string>
using namespace std;

class Task{
private:
string description;
bool completed;

public:
Task(const string& description, bool comp = false);

void setDescription(const string& desc);

string getDescription() const;

void setCompleted(bool comp);

bool isCompleted() const;

};