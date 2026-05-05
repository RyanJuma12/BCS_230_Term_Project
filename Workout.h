//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_WORKOUT_H
#define BCS_230_TERM_PROJECT_WORKOUT_H

#include <string>
using namespace std;

class Workout {
public:
    Workout();

    void logWorkout(const string& userID);
    void viewWorkoutLog(const string& userID);

private:
    bool parseLine(const string& line, string& id, string& name, int& sets, int& reps, double& weight, string& date);
};

#endif //BCS_230_TERM_PROJECT_WORKOUT_H