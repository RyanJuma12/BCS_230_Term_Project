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

        double getWeight();
        double getHeight();
        int getAge();
        string getGender();
    private:
        double weight;
        double height;
        int age;
        string gender;
        string lastUpdateDate;
};



#endif //BCS_230_TERM_PROJECT_PROFILE_H