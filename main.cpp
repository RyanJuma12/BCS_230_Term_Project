#include <iostream>
#include <vector>
#include<ctime>
#include<cmath>

#include "Login.h"
#include "Profile.h"
#include "Workout.h"
#include "Nutrition.h"
#include "Tracker.h"

using namespace std;

/*
This is our term project for BCS_230
It is a Fitness, Nutrition, Tracker designed to help people maintain shape
Contributors: Ryan Juma, Tyler Busching, Taimur Qureshi, David Allendez, Daniel Barradas
Date Created: 4/27/2026
*/

void displayMenu();
int getUserLogin();

int main() {
    Login login;
    Profile profile;
    Workout workout;
    Nutrition nutrition;
    Tracker tracker;

    string userID;
    int loginChoice = getUserLogin();
    int menuChoice;

    if (loginChoice == 1) {
        cout << "Enter User ID: ";
        cin >> userID;
        if (!login.login(userID)) {
            cout << "Login failed. Exiting...\n";
            return 0;
        }
    } else {
        cout << "Enter New User ID: ";
        cin >> userID;
        if (!login.createAccount(userID)) {
            cout << "Account creation failed. Exiting...\n";
            return 0;
        }
    }

    
    do {
        displayMenu();
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:
                profile.updateMeasurements(userID);
                break;
            case 2:
                profile.displayMeasurements(userID);
                break;
            case 3:
                nutrition.logCalories(userID);
                break;
            case 4:
                nutrition.viewCalorieLog(userID);
                break;
            case 5:
                workout.logWorkout(userID);
                break;
            case 6:
                workout.viewWorkoutLog(userID);
                break;
            case 7:
                cout << "Exiting Thank you for using Fitness Tracker!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (menuChoice != 7);
    
}

void displayMenu() {
    cout << "\n==== Fitness Tracker Menu ====\n";
    cout << "1. Update Measurements\n";
    cout << "2. View Measurements\n";
    cout << "3. Log Daily Calories\n";
    cout << "4. View Calorie Log\n";
    cout << "5. Log Workout\n";
    cout << "6. View Workout Log\n";
    cout << "7. Exit\n";
    cout << "Choice: ";
}

int getUserLogin() {
    int choice;

    cout << "==== Welcome to Fitness Tracker ====\n";
    cout << "1. Login\n";
    cout << "2. Create Account\n";
    cout << "Choice: ";
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> choice;
    }

    return choice;
}