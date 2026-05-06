#include <iostream>
#include <vector>
#include<ctime>
#include<cmath>

#include "Login.h"
#include "Profile.h"
#include "Workout.h"
#include "Nutrition.h"
#include "Tracker.h"
#include "Date.h"

using namespace std;

/*
This is our term project for BCS_230
It is a Fitness, Nutrition, Tracker designed to help people maintain shape
Contributors: Ryan Juma, Tyler Busching, Taimur Qureshi, David Allendez, Daniel Barradas
Date Created: 4/27/2026
*/

#include <iostream>

#include "Login.h"
#include "Profile.h"
#include "Workout.h"
#include "Nutrition.h"
#include "Tracker.h"
#include "Date.h"

using namespace std;

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
        if (!login.login(userID)) return 0;
    } else {
        if (!login.createAccount(userID)) return 0;
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
                tracker.calculateMaintenanceCalories(userID);
                break;

            case 8:
                tracker.showDashboard(userID);
                break;

            case 9:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (menuChoice != 9);

    return 0;
}

void displayMenu() {
    cout << "\n==== FITNESS TRACKER MENU ====\n";
    cout << "1. Update Measurements\n";
    cout << "2. View Measurements\n";
    cout << "3. Log Calories\n";
    cout << "4. View Calories\n";
    cout << "5. Log Workout\n";
    cout << "6. View Workout\n";
    cout << "7. Calculate Maintenance Calories\n";
    cout << "8. View Dashboard\n";
    cout << "9. Exit\n";
    cout << "Choice: ";
}

int getUserLogin() {
    int choice;

    cout << "1. Login\n";
    cout << "2. Create Account\n";
    cout << "Choice: ";
    cin >> choice;

    while(choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> choice;
    }

    return choice;
}