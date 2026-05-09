#include "Workout.h"
#include "Date.h"
#include "ConsoleColors.h"  

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Workout::Workout() {}

void Workout::logWorkout(const string& userID) {
    string name, date;
    int sets, reps;
    double weight;

    setColor(CYAN);
    cout << "Workout name: ";
    setColor(WHITE);
    cin >> name;

    setColor(CYAN);
    cout << "Sets: ";
    setColor(WHITE);
    cin >> sets;

    setColor(CYAN);
    cout << "Reps: ";
    setColor(WHITE);
    cin >> reps;

    setColor(CYAN);
    cout << "Weight lifted: ";
    setColor(WHITE);
    cin >> weight;

    date = getCurrentDate();

    ofstream file("data/Workouts.csv", ios::app);

    file << userID << "," << name << "," << sets << "," << reps << "," << weight << "," << date << endl;

    setColor(GREEN);
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
    ifstream file("data/Workouts.csv");
    string line;

    setColor(YELLOW);
    cout << "\n--- Workout Log ---\n";

    while (getline(file, line)) {
        if (line.find(userID) == 0) {

            stringstream ss(line);

            string id, name, sets, reps, weight, date;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, sets, ',');
            getline(ss, reps, ',');
            getline(ss, weight, ',');
            getline(ss, date, ',');

            cout << "Workout: " << name
                 << " | Sets: " << sets
                 << " | Reps: " << reps
                 << " | Weight: " << weight
                 << " | Date: " << date << endl;
        }
    }

    cout << "Great Job, and make sure to stay Consistant!" << endl;
}