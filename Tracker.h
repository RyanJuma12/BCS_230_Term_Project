//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_TRACKER_H
#define BCS_230_TERM_PROJECT_TRACKER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Profile.h"
#include "Workout.h"

using namespace std;

class Tracker {
public:
    Tracker();

    double calculateWeeklyWorkoutHours(const string& userID);
    double calculateWeeklyWorkoutReps(const string& userID);
    double calculateWeeklyWeightLifted(const string& userID);
    int calculateWeeklyWorkoutSets(const string& userID);

    double calculateWeightChange(double initialWeight, double finalWeight);

    void calculateMaintenanceCalories(const string& userID);
    double getMaintenanceCalories();

private:
    Profile profile;
    Workout workout;

    double weeklyWorkoutHours;
    double weeklyWorkoutReps;
    double weeklyWeightLifted;
    double weightChange;
    int weeklyWorkoutSets;

    string activityLevel;
    double maintenanceCalories;

    // helper for weekly filtering (used in cpp)
    struct DateParts {
        int m, d, y;
    };
};

#endif //BCS_230_TERM_PROJECT_TRACKER_H 