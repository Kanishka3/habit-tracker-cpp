#ifndef HABITTRACKER_H
#define HABITTRACKER_H

#include <vector>
#include <string>

using namespace std;

struct Habit {
    string name;
    int streak;
    bool completedToday;
};

class HabitTracker {
private:
    vector<Habit> habits;

public:
    void addHabit();
    void viewHabits();
    void completeHabit();
    void saveToFile();
    void loadFromFile();
};

#endif