#define STUDENT_H

#include<string>
using namespace std;


struct Student
{
    int id;
    string name;
    int age;
};

struct Node{

    Student student;
    Node* next;

};