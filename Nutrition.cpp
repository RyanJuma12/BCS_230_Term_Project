#include "Nutrition.h"
#include "Date.h"
#include "ConsoleColors.h"

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

    setColor(CYAN);
    cout << "Enter goal\n";
    cout << "1. Maintain\n"
         << "2. Lose Weight\n"
         << "3. Gain Muscle\n";

    int goalChoice;
    setColor(WHITE);
    cin >> goalChoice;

    switch (goalChoice) {
        case 1:
            setColor(CYAN);
            goal = "Maintain";
            break;
        case 2:
            setColor(CYAN);
            goal = "Lose Weight";
            break;
        case 3:
            setColor(CYAN);
            goal = "Gain Muscle";
            break;
        default:
            setColor(RED);
            cout << "Invalid choice. Defaulting to Maintain.\n";
            goal = "Maintain";
    }

    ofstream outFile("data/Nutrition.csv", ios::app);

    if (outFile.is_open()) {
        outFile << userID << "," << caloriesConsumed << "," << goal << "," << logDate << endl;

        setColor(GREEN);
        cout << "Calorie log updated successfully!\n";
    }
    else {
        setColor(RED);
        cerr << "Error opening file for writing.\n";
    }
}


void Nutrition::viewCalorieLog(string& userID)
{
    string firstName;
    string lastName;

    Buddyz login;
    login.getUserName(userID, firstName, lastName);

    ifstream inFile("data/Nutrition.csv");

    if (!inFile.is_open()) {
        setColor(RED);
        cout << "No calorie log found.\n";
        return;
    }

    string line;
    bool found = false;

    setColor(YELLOW);
    cout << "\nCalorie Log for User: " << firstName << " " << lastName << endl;

    while (getline(inFile, line)) {
        stringstream ss(line);

        string uid, cal, g, date;

        getline(ss, uid, ',');
        getline(ss, cal, ',');
        getline(ss, g, ',');
        getline(ss, date, ',');

        if (uid == userID) {
            setColor(YELLOW);
            cout << "Date: " << date
                 << ", Calories: " << cal
                 << ", Goal: " << g << endl;
            
            found = true;
        }
    }

    if (!found) {
        setColor(RED);
        cout << "No entries found for this user.\n";
    }

    if (found) {
        setColor(YELLOW);
        cout << "Keep up the great work, and track your calories! :)" << endl;
    }

    inFile.close();
}


int Nutrition::getDailyCalorieIntake(string& userID){
    setColor(CYAN);
    cout << "Enter calories consumed today: ";
    setColor(WHITE);
    cin >> caloriesConsumed;

    while (cin.fail() || caloriesConsumed <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        setColor(RED);
        cout << "Invalid input. Enter a positive number: ";
        cin >> caloriesConsumed;
    }

    return caloriesConsumed;
}