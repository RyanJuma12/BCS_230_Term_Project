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

    double calculateWeeklyWorkoutReps(const string& userID);
    double calculateWeeklyWorkoutSets(const string& userID);
    double calculateWeeklyWeightLifted(const string& userID);

    double calculateWeightChange(double initialWeight, double finalWeight);

    void calculateMaintenanceCalories(const string& userID);
    double getMaintenanceCalories();

    void showDashboard(const string& userID);

private:
    Profile profile;
    Workout workout;

    double weeklyWorkoutReps;
    double weeklyWorkoutSets;
    double weeklyWeightLifted;

    double maintenanceCalories;
    string activityLevel;
};

#endif //BCS_230_TERM_PROJECT_TRACKER_H