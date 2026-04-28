//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_PROFILE_H
#define BCS_230_TERM_PROJECT_PROFILE_H

#include <iostream>
#include <string>
#include <fstream>
#include<vector>
using namespace std;

class Profile {
    private:
        double weight;
        double height;
        string lastUpdateDate;

    public:
        Profile(); // Constructor to initialize default values

        void updateMeasurements(const string& userID);
        void displayMeasurements(const string& userID);

        double getWeight();
        double getHeight();

};



#endif //BCS_230_TERM_PROJECT_PROFILE_H