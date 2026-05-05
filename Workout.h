//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_WORKOUT_H
#define BCS_230_TERM_PROJECT_WORKOUT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Workout {
    public:
        Workout(); // Constructor to initialize default values

        void logWorkout(const string& userID);
        void getDailydailyWorkoutLog(const string& userID);
        void viewWorkoutLog(const string& userID);

        int getSets(const string& userID);
        int getReps(const string& userID);
        double getWeightLifted(const string& userID);
    private:
        int sets;
        int reps;
        double weightLifted;
        string workoutDate;
        string workoutName;
};


#endif //BCS_230_TERM_PROJECT_WORKOUT_H