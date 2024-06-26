// Student.cpp

#include "Student.h"
#include <iostream>

// Constructor implementation
Student::Student(std::string n, int r, float m) {
    name = n;
    rollNumber = r;
    marks = m;
}

// Display method implementation
void Student::display() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Roll Number: " << rollNumber << std::endl;
    std::cout << "Marks: " << marks << std::endl;
}

// Update marks method implementation
void Student::updateMarks(float newMarks) {
    marks = newMarks;
}
