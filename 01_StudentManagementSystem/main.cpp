//main.cpp file for student Management system
#include"Student.h"
#include<iostream>
#include<vector>

using namespace std;

int main()
{

    vector<Student> students;

    Student s1("vaishnavi", 101, 85.5);
    Student s2("Nilam", 100, 80.6);

    //we use pack method to add student to the vector
    students.push_back(s1);
    students.push_back(s2);

    cout<<"Displaying all students: "<<endl;

    for(const auto& student : students)  //works like for i = student 
    {
        student.display();
        cout<<endl;
    }

    students[0].updateMarks(90.09);

    cout<<"Displaying updated marks details : "<<endl;
    students[0].display();

    return 0;
}