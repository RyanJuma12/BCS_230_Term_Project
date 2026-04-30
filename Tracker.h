//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_TRACKER_H
#define BCS_230_TERM_PROJECT_TRACKER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Tracker {
public:
    int calculateBMI(double weight, double height);
    void displayBMICategory(int bmi);

    double calculateWeeklyWorkoutHours(const string& userID);
    double calculateWeeklyWorkoutReps(const string& userID);
    double calculateWeeklyWeightLifted(const string& userID);
    int calculateWeeklyWorkoutSets(const string& userID);

    double calculateWeightChange(double initialWeight, double finalWeight);

private:
    double weeklyWorkoutHours;
    double weeklyWorkoutReps;
    double weeklyWeightLifted;
    double weightChange;
    int weeklyWorkoutSets;

};


#endif //BCS_230_TERM_PROJECT_TRACKER_H