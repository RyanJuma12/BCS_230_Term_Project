//
// Created by on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_NUTRITION_H
#define BCS_230_TERM_PROJECT_NUTRITION_H

#include <iostream>
#include <string>
using namespace std;

class Nutrition{
    public: 
        void logCalories();
        void viewCalorieLog();
        int getdailyCalorieIntake();
    private:
        int caloriesConsumed;
        string logDate;
    

};

#endif //BCS_230_TERM_PROJECT_NUTRITION_H