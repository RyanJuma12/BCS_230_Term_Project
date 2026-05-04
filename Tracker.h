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

using namespace std;

class Tracker {
public:
    
    double calculateWeeklyWorkoutHours(const string& userID);
    double calculateWeeklyWorkoutReps(const string& userID);
    double calculateWeeklyWeightLifted(const string& userID);
    int calculateWeeklyWorkoutSets(const string& userID);

    double calculateWeightChange(double initialWeight, double finalWeight);
    double getMaintenanceCalories();
    void calculateMaintenanceCalories(Profile& profile);

private:
    double weeklyWorkoutHours;
    double weeklyWorkoutReps;
    double weeklyWeightLifted;
    double weightChange;
    int weeklyWorkoutSets;
    string activityLevel;
    double maintenanceCalories;

};


#endif //BCS_230_TERM_PROJECT_TRACKER_H