#include "Tracker.h"
#include "Date.h"
#include "Profile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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

int Tracker::calculateWeeklyWorkoutSets(const string& userID) {
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

    weeklyWorkoutSets = total / count;
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
    weightChange = finalWeight - initialWeight;
    return weightChange;
}

void Tracker::calculateMaintenanceCalories(const string& userID) {
    cout << "Enter your activity level\n";
    cout << "1. Sedentary (little or no exercise)\n";
    cout << "2. Lightly active (light exercise/sports 1-3 days/week)\n";
    cout << "3. Moderately active (moderate exercise/sports 3-5 days/week)\n";
    cout << "4. Very active (hard exercise/sports 6-7 days a    week)\n";
    cout << "5. Extra active (very hard exercise/sports & physical job or 2x training)\n";      

    int choice;
    cin >> choice;  
    if (choice == 1) activityLevel = "sedentary";
    else if (choice == 2) activityLevel = "lightly active";
    else if (choice == 3) activityLevel = "moderately active";
    else if (choice == 4) activityLevel = "very active";
    else if (choice == 5) activityLevel = "extra active";
    else {
        cout << "Invalid choice. Defaulting to Sedentary.\n";
        activityLevel = "sedentary";
     }

    int age = profile.getAge(userID);
    string gender = profile.getGender(userID);
    double weight = profile.getWeight(userID);
    double height = profile.getHeight(userID);

    double weightKg = weight * 0.453592;
    double heightCm = height * 2.54;

    double bmr = 0.0;

    if (gender == "Male") {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age + 5;
    } else {
        bmr = 10 * weightKg + 6.25 * heightCm - 5 * age - 161;
    }

    double factor = 1.2;

    if (activityLevel == "sedentary") factor = 1.2;
    else if (activityLevel == "lightly active") factor = 1.375;
    else if (activityLevel == "moderately active") factor = 1.55;
    else if (activityLevel == "very active") factor = 1.725;
    else if (activityLevel == "extra active") factor = 1.9;

    maintenanceCalories = bmr * factor;

    cout << "Your maintenance calories: " << maintenanceCalories << endl;
}


double Tracker::getMaintenanceCalories() {
    return maintenanceCalories;
}