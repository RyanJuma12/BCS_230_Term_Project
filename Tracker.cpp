#include "Tracker.h"
#include "Date.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Tracker::Tracker() {
    weeklyWorkoutReps = 0;
    weeklyWorkoutSets = 0;
    weeklyWeightLifted = 0;
    maintenanceCalories = 0;
    activityLevel = "";
}


double Tracker::calculateWeeklyWorkoutReps(const string& userID) {
    ifstream file("Workouts.csv");
    string line;

    int total = 0;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string id, name, sets, reps, weight, date;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, sets, ',');
        getline(ss, reps, ',');
        getline(ss, weight, ',');
        getline(ss, date, ',');

        if (id == userID) {
            total += stoi(reps);
            count++;
        }
    }

    if (count == 0) return 0;

    weeklyWorkoutReps = (double)total / count;
    return weeklyWorkoutReps;
}


double Tracker::calculateWeeklyWorkoutSets(const string& userID) {
    ifstream file("Workouts.csv");
    string line;

    int total = 0;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string id, name, sets, reps, weight, date;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, sets, ',');
        getline(ss, reps, ',');
        getline(ss, weight, ',');
        getline(ss, date, ',');

        if (id == userID) {
            total += stoi(sets);
            count++;
        }
    }

    if (count == 0) return 0;

    weeklyWorkoutSets = (double)total / count;
    return weeklyWorkoutSets;
}


double Tracker::calculateWeeklyWeightLifted(const string& userID) {
    ifstream file("Workouts.csv");
    string line;

    double total = 0;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string id, name, sets, reps, weight, date;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, sets, ',');
        getline(ss, reps, ',');
        getline(ss, weight, ',');
        getline(ss, date, ',');

        if (id == userID) {
            total += stod(weight);
            count++;
        }
    }

    if (count == 0) return 0;

    weeklyWeightLifted = total / count;
    return weeklyWeightLifted;
}


double Tracker::calculateWeightChange(double initialWeight, double finalWeight) {
    return finalWeight - initialWeight;
}


void Tracker::calculateMaintenanceCalories(const string& userID) {

    int age = profile.getAge(userID);
    string gender = profile.getGender(userID);
    double weight = profile.getWeight(userID);
    double height = profile.getHeight(userID);

    cout << "Choose activity level:\n";
    cout << "1. Sedentary\n2. Light\n3. Moderate\n4. Very Active\n5. Extra Active\n";
    int choice;
    cin >> choice;

    if (choice == 1) activityLevel = "sedentary";
    else if (choice == 2) activityLevel = "light";
    else if (choice == 3) activityLevel = "moderate";
    else if (choice == 4) activityLevel = "very";
    else activityLevel = "extra";

    double weightKg = weight * 0.453592;
    double heightCm = height * 2.54;

    double bmr;

    if (gender == "Male")
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age + 5;
    else
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age - 161;

    double factor = 1.2;

    if (activityLevel == "light") factor = 1.375;
    else if (activityLevel == "moderate") factor = 1.55;
    else if (activityLevel == "very") factor = 1.725;
    else if (activityLevel == "extra") factor = 1.9;

    maintenanceCalories = bmr * factor;

    cout << "Maintenance Calories: " << maintenanceCalories << endl;
}

double Tracker::getMaintenanceCalories() {
    return maintenanceCalories;
}


void Tracker::showDashboard(const string& userID) {
    cout << "\n===== FITNESS DASHBOARD =====\n";

    cout << "Maintenance Calories: "
         << maintenanceCalories << endl;

    cout << "Avg Reps: "
         << calculateWeeklyWorkoutReps(userID) << endl;

    cout << "Avg Sets: "
         << calculateWeeklyWorkoutSets(userID) << endl;

    cout << "Avg Weight Lifted: "
         << calculateWeeklyWeightLifted(userID) << endl;

    cout << "=============================\n";
}