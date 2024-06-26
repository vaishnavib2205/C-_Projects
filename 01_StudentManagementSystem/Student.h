// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int rollNumber;
    float marks;

public:
    // Constructor
    Student(std::string n, int r, float m);

    // Display method
    void display() const;

    // Update marks method
    void updateMarks(float newMarks);
};

#endif // STUDENT_H
