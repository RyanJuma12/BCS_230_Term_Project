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
    
}

void Workout::viewWorkoutLog(const string& userID) {
    
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

