//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_WORKOUT_H
#define BCS_230_TERM_PROJECT_WORKOUT_H

#include <iostream>
#include <string>
#include <fstream>
#include<vector>
using namespace std;


class Workout {
    public:
        void logWorkout();
        void viewWorkoutLog();
        
        int getSets();
        int getReps();
        double getWeightLifted();
    private:
        int sets;
        int reps;
        double weightLifted;
        string workoutDate;
        string workoutName;
};

#endif //BCS_230_TERM_PROJECT_WORKOUT_H