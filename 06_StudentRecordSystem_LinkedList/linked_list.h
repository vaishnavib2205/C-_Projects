#define LINKED_LIST_H
#include"student.h"

class LinkedList{
private:
    Node* head;
    Node* first;
    Node* second;
    Node* third;

public:
    LinkedList(); //constructor of class linkedlist
   
    void addStudent(int id, string name, int age);
    void displayStudents();
    void deleteStudent(int id);

    ~LinkedList(); //destructor of linkedlist constructor instance
};