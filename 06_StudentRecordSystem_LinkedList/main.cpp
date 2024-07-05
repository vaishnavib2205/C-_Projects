#include<iostream>
#include<string>
#include"linked_list.h"

using namespace std;

int main()
{
    LinkedList list;
    int choice, id, age;
    string name;

    while(true)
    {
        cout<<"\n STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout<<"1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

           switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                list.addStudent(id, name, age);
                break;
            case 2:
                list.displayStudents();
                break;
            case 3:
                cout << "Enter ID of the student to delete: ";
                cin >> id;
                list.deleteStudent(id);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}



