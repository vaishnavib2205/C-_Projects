#include <iostream>
#include "ToDoList.h"
using namespace std;


void showMenu() {
    cout << "1. Add Task\n";
    cout << "2. Delete Task\n";
    cout << "3. Update Task\n";
    cout << "4. Mark Task Completed\n";
    cout << "5. Save Tasks to File\n";
    cout << "6. Load Tasks from File\n";
    cout << "7. Display Tasks\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    ToDoList toDoList;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            getline(cin, description);
            toDoList.addTask(Task(description));
        } else if (choice == 2) {
            int index;
            cout << "Enter task number to delete: ";
            cin >> index;
            cin.ignore();
            toDoList.deleteTask(index - 1);
        } else if (choice == 3) {
            int index;
            string description;
            cout << "Enter task number to update: ";
            cin >> index;
            cin.ignore();
            cout << "Enter new task description: ";
            getline(cin, description);
            toDoList.updateTask(index - 1, Task(description));
        } else if (choice == 4) {
            int index;
            cout << "Enter task number to mark as completed: ";
            cin >> index;
            cin.ignore();
            toDoList.markTaskCompleted(index - 1);
        } else if (choice == 5) {
            string filename;
            cout << "Enter filename to save tasks: ";
            cin >> filename;
            toDoList.saveToFile(filename);
        } else if (choice == 6) {
            string filename;
            cout << "Enter filename to load tasks: ";
            cin >> filename;
            toDoList.loadFromFile(filename);
        } else if (choice == 7) {
            toDoList.displayTasks();
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
