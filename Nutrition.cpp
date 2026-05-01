#include "Nutrition.h"
#include <iostream>
#include <fstream>
#include <ctime>

Nutrition::Nutrition() {
    caloriesConsumed = 0;
    logDate = " ";
    
}

string getCurrentDate()
{
    time_t now = time(0); //system time
    char* dt = ctime(&now);
    return dt;
}

void logCalories(string& userID)
{

}
void viewCalorieLog(string& userID)
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
}