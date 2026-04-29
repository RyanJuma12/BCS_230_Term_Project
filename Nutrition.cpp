#include "Nutrition.h"
#include <iostream>
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

void logCalories()
{

}
void viewCalorieLog()
{

}
int Nutrition::getdailyCalorieIntake()
{
    cout << "Enter the amount of calories you ate today" << endl;
    cin >> caloriesConsumed;
    logDate = getCurrentDate();

    ofstream outFile("nutrition.csv", ios::app);
    if (outFile.is_open()) {
        outFile << userID <<
    }
}