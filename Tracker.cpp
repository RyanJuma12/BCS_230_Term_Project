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
    activityLevel = "";
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
    cin.ignore(); // to handle newline
    getline(cin, activityLevel);

    int age       = getAge(const string& userID);
    string gender = getGender(const string& userID);
    double weight = getWeight(const string& userID);
    double height = getHeight(const string& userID);

    double weightKg = weight * 0.453592; // lbs to kg
    double heightCm = height * 2.54; // inches to cm
    double bmr = 0.0;
    if (gender == "M" || gender == "m") {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age + 5;
    } else if (gender == "F" || gender == "f") {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age - 161;
    } else {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age + 5; // default to male
    }
    double factor = 1.2; // sedentary
    if (activityLevel == "lightly active") factor = 1.375;
    else if (activityLevel == "moderately active") factor = 1.55;
    else if (activityLevel == "very active") factor = 1.725;
    else if (activityLevel == "extra active") factor = 1.9;
    maintenanceCalories = bmr * factor;
    cout << "Your maintenance calories: " << maintenanceCalories << " calories/day" << endl;
}

double Tracker::getMaintenanceCalories() {
    return maintenanceCalories;
}

void Tracker::getAge(const string& userID) {
    
}

void Tracker::getGender(const string& userID) {
    // Implementation
}

void Tracker::getWeight(const string& userID) {
    // Implementation
}

void Tracker::getHeight(const string& userID) {
    // Implementation
}