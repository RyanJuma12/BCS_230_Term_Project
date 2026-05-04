#include "Workout.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

Workout::Workout() {
    sets = 0;
    reps = 0;
    weightLifted = 0.0;
    workoutDate = "";
    workoutName = "";
}

void Workout::logWorkout(const string& userID) {
    cout << "Enter workout name: ";
    cin >> workoutName;

    cout << "Enter Total number of sets: ";
    cin >> sets;

    cout << "Enter Total number of reps: ";
    cin >> reps;

    cout << "Enter Total weight lifted (lbs): ";
    cin >> weightLifted;

    workoutDate = getCurrentDate();

    ofstream outFile("Workouts.csv", ios::app);
    if (outFile.is_open()) {
        outFile << userID << "," << workoutName << "," << sets << "," << reps << "," << weightLifted << "," << workoutDate << endl;
        outFile.close();
        cout << "Workout logged successfully!" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }

}



void Workout::viewWorkoutLog(const string& userID) {
    ifstream inFile("Workouts.csv");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        cout << "Workout Log for User ID: " << userID << endl;
        while (getline(inFile, line)) {
            if (line.find(userID) == 0) {
                found = true;
                cout << line << endl; // You can format this output as needed
            }
        }
        if (!found) {
            cout << "No workouts found for User ID: " << userID << endl;
        }
        inFile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
}

int Workout::getSets() {
    return sets;
}

int Workout::getReps() {
    return reps;
}

double Workout::getWeightLifted() {
    return weightLifted;
}

