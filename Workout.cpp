#include "Workout.h"
#include "Date.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Workout::Workout() {}

void Workout::logWorkout(const string& userID) {
    string name, date;
    int sets, reps;
    double weight;

    cout << "Workout name: ";
    cin >> name;

    cout << "Sets: ";
    cin >> sets;

    cout << "Reps: ";
    cin >> reps;

    cout << "Weight lifted: ";
    cin >> weight;

    date = getCurrentDate();

    ofstream file("Workouts.csv", ios::app);

    file << userID << "," << name << "," << sets << "," << reps << "," << weight << "," << date << endl;

    cout << "Workout logged.\n";
}

bool Workout::parseLine(const string& line, string& id, string& name, int& sets, int& reps, double& weight, string& date) {

    stringstream ss(line);
    string setsStr, repsStr, weightStr;

    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, setsStr, ',');
    getline(ss, repsStr, ',');
    getline(ss, weightStr, ',');
    getline(ss, date, ',');

    sets = stoi(setsStr);
    reps = stoi(repsStr);
    weight = stod(weightStr);

    return true;
}

void Workout::viewWorkoutLog(const string& userID) {
    ifstream file("Workouts.csv");
    string line;

    while (getline(file, line)) {
        if (line.find(userID) == 0) {
            cout << line << endl;
        }
    }
}