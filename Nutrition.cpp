#include "Nutrition.h"
#include "Date.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

Nutrition::Nutrition() {
    caloriesConsumed = 0;
    logDate = "";
    goal = "";
}


void Nutrition::logCalories(string& userID)
{
    caloriesConsumed = getDailyCalorieIntake(userID);
    logDate = getCurrentDate();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter goal\n";
    cout << "1. Maintain\n"
         << "2. Lose Weight\n"
         << "3. Gain Muscle\n";

    int goalChoice;
    cin >> goalChoice;

    switch (goalChoice) {
        case 1:
            goal = "Maintain";
            break;
        case 2:
            goal = "Lose Weight";
            break;
        case 3:
            goal = "Gain Muscle";
            break;
        default:
            cout << "Invalid choice. Defaulting to Maintain.\n";
            goal = "Maintain";
    }

    ofstream outFile("data/Nutrition.csv", ios::app);

    if (outFile.is_open()) {
        outFile << userID << "," << caloriesConsumed << "," << goal << "," << logDate << endl;

        cout << "Calorie log updated successfully!\n";
    }
    else {
        cerr << "Error opening file.\n";
    }
}


void Nutrition::viewCalorieLog(string& userID)
{
    ifstream inFile("data/Nutrition.csv");

    if (!inFile.is_open()) {
        cout << "No calorie log found.\n";
        return;
    }

    string line;
    bool found = false;

    cout << "Calorie Log for " << userID << ":\n";

    while (getline(inFile, line)) {
        stringstream ss(line);

        string uid, cal, g, date;

        getline(ss, uid, ',');
        getline(ss, cal, ',');
        getline(ss, g, ',');
        getline(ss, date, ',');

        if (uid == userID) {
            cout << "Date: " << date
                 << ", Calories: " << cal
                 << ", Goal: " << g << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "No entries found for this user.\n";
    }

    inFile.close();
}


int Nutrition::getDailyCalorieIntake(string& userID)
{
    cout << "Enter calories consumed today: ";
    cin >> caloriesConsumed;

    while (cin.fail() || caloriesConsumed <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Enter a positive number: ";
        cin >> caloriesConsumed;
    }

    return caloriesConsumed;
}