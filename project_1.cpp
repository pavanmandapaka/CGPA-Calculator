#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    string description;
    bool completed;

    Task(int id, const string& description)
        : id(id), description(description), completed(false) {}
};

void displayMenu() {
    cout << "\n========== TO-DO LIST ==========\n";
    cout << "1. Add a Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete a Task\n";
    cout << "5. Exit\n";
    cout << "================================\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks, int& nextId) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore(); 
    getline(cin, description);
    tasks.emplace_back(nextId++, description);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the to-do list.\n";
        return;
    }

    cout << "\nYour To-Do List:\n";
    for (const auto& task : tasks) {
        cout << "[" << (task.completed ? "X" : " ") << "] "
             << "ID: " << task.id << " - " << task.description << "\n";
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    int id;
    cout << "Enter the ID of the task to mark as completed: ";
    cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            if (!task.completed) {
                task.completed = true;
                cout << "Task marked as completed!\n";
            } else {
                cout << "Task is already completed.\n";
            }
            return;
        }
    }

    cout << "Task with ID " << id << " not found.\n";
}

void deleteTask(vector<Task>& tasks) {
    int id;
    cout << "Enter the ID of the task to delete: ";
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted successfully!\n";
            return;
        }
    }

    cout << "Task with ID " << id << " not found.\n";
}

int main() {
    vector<Task> tasks;
    int nextId = 1;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, nextId);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List app. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
