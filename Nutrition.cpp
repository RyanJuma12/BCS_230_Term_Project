#include "Nutrition.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <ctime>

Nutrition::Nutrition() {
    caloriesConsumed = 0;
    logDate = " ";
    
}


void Nutrition::logCalories(string& userID)
{

}
void Nutrition::viewCalorieLog(string& userID)
{

}
int Nutrition::getdailyCalorieIntake(string& userID)
{
    cout << "Enter the amount of calories you ate today" << endl;
    cin >> caloriesConsumed;
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
    return caloriesConsumed;
}