#include "Nutrition.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <limits>
#include <sstream>

Nutrition::Nutrition() {
    caloriesConsumed = 0;
    logDate = " ";
    
}


void Nutrition::logCalories(string& userID)
{
    caloriesConsumed = getdailyCalorieIntake(userID);
    logDate = getCurrentDate();

    ofstream outFile("nutrition.csv", ios::app);
    if (outFile.is_open()) {
        outFile << userID << "," << caloriesConsumed << "," << logDate << endl;
        outFile.close();
        cout << "Calorie log updated successfully!" << endl;
    }
    else {
        cerr << "Error opening file for writing." << endl;
    }
}
void Nutrition::viewCalorieLog(string& userID)
{
    ifstream inFile("nutrition.csv");
    if (!inFile.is_open()) {
        cout << "No calorie log found." << endl;
        return;
    }

    string line;
    bool found = false;
    cout << "Calorie Log for " << userID << ":" << endl;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string uid, cal, date;
        getline(ss, uid, ',');
        getline(ss, cal, ',');
        getline(ss, date, ',');
        if (uid == userID) {
            cout << "Date: " << date << ", Calories: " << cal << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found for this user." << endl;
    }
    inFile.close();
}
int Nutrition::getdailyCalorieIntake(string& userID)
{
    cout << "Enter the amount of calories you ate today: ";
    cin >> caloriesConsumed;
    while (cin.fail() || caloriesConsumed <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer for calories: ";
        cin >> caloriesConsumed;
    }
    return caloriesConsumed;
}