#include <iostream>
#include <fstream>
#include "HabitTracker.h"

using namespace std;

void HabitTracker::addHabit() {
    Habit h;
    cin.ignore();
    cout << "Enter habit name: ";
    getline(cin, h.name);

    h.streak = 0;
    h.completedToday = false;

    habits.push_back(h);
    cout << "Habit added successfully.\n";
}

void HabitTracker::viewHabits() {
    if (habits.empty()) {
        cout << "No habits found.\n";
        return;
    }

    cout << "\n--- Habit List ---\n";

    for (int i = 0; i < habits.size(); i++) {
        cout << i + 1 << ". " << habits[i].name
             << " | Streak: " << habits[i].streak
             << " | Completed Today: "
             << (habits[i].completedToday ? "Yes" : "No")
             << endl;
    }
}

void HabitTracker::completeHabit() {
    if (habits.empty()) {
        cout << "No habits available.\n";
        return;
    }

    viewHabits();

    int num;
    cout << "Choose habit number: ";
    cin >> num;

    if (num < 1 || num > habits.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    if (!habits[num - 1].completedToday) {
        habits[num - 1].completedToday = true;
        habits[num - 1].streak++;
        cout << "Habit marked complete.\n";
    } else {
        cout << "Already completed today.\n";
    }
}

void HabitTracker::saveToFile() {
    ofstream file("habits.txt");

    for (int i = 0; i < habits.size(); i++) {
        file << habits[i].name << endl;
        file << habits[i].streak << endl;
        file << habits[i].completedToday << endl;
    }

    file.close();
    cout << "Data saved.\n";
}

void HabitTracker::loadFromFile() {
    ifstream file("habits.txt");

    if (!file) {
        return;
    }

    Habit h;

    while (getline(file, h.name)) {
        file >> h.streak;
        file >> h.completedToday;
        file.ignore();

        habits.push_back(h);
    }

    file.close();
}