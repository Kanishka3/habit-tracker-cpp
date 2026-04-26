#include <iostream>
#include "HabitTracker.h"

using namespace std;

int main() {
    HabitTracker tracker;
    tracker.loadFromFile();

    int choice;

    do {
        cout << "\n===== Personal Habit Tracker =====\n";
        cout << "1. Add Habit\n";
        cout << "2. View Habits\n";
        cout << "3. Complete Habit\n";
        cout << "4. Save Data\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tracker.addHabit();
                break;
            case 2:
                tracker.viewHabits();
                break;
            case 3:
                tracker.completeHabit();
                break;
            case 4:
                tracker.saveToFile();
                break;
            case 5:
                tracker.saveToFile();
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again. \n";
        }

    } while (choice != 5);

    return 0;
}