#include "linked_list.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

// Adds a student to the singly linked list
void LinkedList::addStudent(int id, string name, int age) {
    Node* newNode = new Node();
    newNode->student.id = id;
    newNode->student.name = name;
    newNode->student.age = age;
    newNode->next = head;
    head = newNode;

    cout << "Student added successfully!\n";
}

// Displays all students in the singly linked list
void LinkedList::displayStudents() {
    if (head == nullptr) {
        cout << "No students to display.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->student.id << ", Name: " << temp->student.name << ", Age: " << temp->student.age << endl;
        temp = temp->next;
    }
}

// Deletes a student by ID from the singly linked list
void LinkedList::deleteStudent(int id) {
    if (head == nullptr) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->student.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    if (temp == head) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Student deleted successfully!\n";
}

// Destructor to clean up all nodes in the singly linked list
LinkedList::~LinkedList() {
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}
