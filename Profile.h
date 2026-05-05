//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_PROFILE_H
#define BCS_230_TERM_PROJECT_PROFILE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Profile {
    public:
        Profile();

        void updateMeasurements(const string& userID);
        void displayMeasurements(const string& userID);

        double getWeight(const string& userID);
        double getHeight(const string& userID);
        int getAge(const string& userID);
        string getGender(const string& userID);
    private:
        double weight;
        double height;
        int age;
        string gender;
        string lastUpdateDate;
};



#endif //BCS_230_TERM_PROJECT_PROFILE_H