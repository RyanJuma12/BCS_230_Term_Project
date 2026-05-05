#include "Tracker.h"
#include "Date.h"
#include "Profile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

Tracker::Tracker() {
    weeklyWorkoutHours = 0.0;
    weeklyWorkoutReps = 0.0;
    weeklyWorkoutSets = 0;
    weeklyWeightLifted = 0.0;
    weightChange = 0.0;
    activityLevel = " ";
    maintenanceCalories = 0.0;
}

double Tracker::calculateWeeklyWorkoutHours(const string& userID) {
    // Implementation to calculate weekly workout hours based on workout logs
    return 0.0; // Placeholder return value
}

double Tracker::calculateWeeklyWorkoutReps(const string& userID) {
    // Implementation to calculate weekly workout reps based on workout logs
    return 0.0; // Placeholder return value
}

double Tracker::calculateWeeklyWeightLifted(const string& userID) {
    // Implementation to calculate weekly weight lifted based on workout logs
    return 0.0; // Placeholder return value
}

int Tracker::calculateWeeklyWorkoutSets(const string& userID) {
    // Implementation to calculate weekly workout sets based on workout logs
    return 0; // Placeholder return value
}

double Tracker::calculateWeightChange(double initialWeight, double finalWeight) {
    weightChange = finalWeight - initialWeight;
    return weightChange;
}

void Tracker::calculateMaintenanceCalories(const string& userID) {
    cout << "Enter your activity level (sedentary, lightly active, moderately active, very active, extra active): ";
    cin.ignore();
    getline(cin, activityLevel);

    int age = profile.getAge(userID);
    string gender = profile.getGender(userID);
    double weight = profile.getWeight(userID);
    double height = profile.getHeight(userID);

    double weightKg = weight * 0.453592;
    double heightCm = height * 2.54;

    double bmr = 0.0;

    if (gender == "M" || gender == "m") {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age + 5;
    } else {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age - 161;
    }

    double factor = 1.2;

    if (activityLevel == "lightly active") factor = 1.375;
    else if (activityLevel == "moderately active") factor = 1.55;
    else if (activityLevel == "very active") factor = 1.725;
    else if (activityLevel == "extra active") factor = 1.9;

    maintenanceCalories = bmr * factor;

    cout << "Your maintenance calories: " << maintenanceCalories << endl;
}

double Tracker::getMaintenanceCalories() {
    return maintenanceCalories;
}



