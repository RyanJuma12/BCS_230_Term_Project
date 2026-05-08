#include "Profile.h"
#include "Date.h"
#include "ConsoleColors.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

Profile::Profile() {}

void Profile::updateMeasurements(const string& userID) {
    int age, choice;
    double weight, height;
    string gender;

    setColor(CYAN);
    cout << "Enter your age (years): ";
    setColor(WHITE);
    cin >> age;

    setColor(CYAN);
    cout << "Enter your weight (lbs): ";
    setColor(WHITE);    
    cin >> weight;

    setColor(CYAN);
    cout << "Enter your height (inches): ";
    setColor(WHITE);
    cin >> height;

    setColor(CYAN);
    cout << "Enter your gender (1.M, 2.F): ";
    setColor(WHITE);
    cin >> choice;
    if (choice == 1){
        gender = "Male";
    } else if (choice == 2){
        gender = "Female";
    } else {
        setColor(RED);
        cout << "Invalid choice. Defaulting to  Male.\n";
        gender = "Male";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string date = getCurrentDate();

    ofstream file("data/Profile.csv", ios::app);

    if (file.is_open()) {
        file << userID << ","
             << age << ","
             << height << ","
             << weight << ","
             << gender << ","
             << date << endl;

        setColor(GREEN);
        cout << "Profile updated successfully!\n";
    } else {
        setColor(RED);
        cerr << "Error opening Profile.csv\n";
    }
}

bool Profile::loadProfile(const string& userID, int& age, double& height, double& weight, string& gender, string& date) {

    ifstream file("data/Profile.csv");
    if (!file.is_open()) return false;

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);

        string id, ageStr, heightStr, weightStr, genderStr, dateStr;

        getline(ss, id, ',');

        if (id == userID) {
            getline(ss, ageStr, ',');
            getline(ss, heightStr, ',');
            getline(ss, weightStr, ',');
            getline(ss, genderStr, ',');
            getline(ss, dateStr, ',');

            age = stoi(ageStr);
            height = stod(heightStr);
            weight = stod(weightStr);
            gender = genderStr;
            date = dateStr;

            found = true; // keep going → get latest entry
        }
    }

    return found;
}


double Profile::getWeight(const string& userID) {
    int age;
    double height, weight;
    string gender, date;

    if (loadProfile(userID, age, height, weight, gender, date))
        return weight;

    return 0.0;
}

double Profile::getInitialWeight(const string& userID) {

    ifstream file("data/Profile.csv");

    if (!file.is_open()) {
        return 0.0;
    }

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        string id;
        string ageStr;
        string heightStr;
        string weightStr;
        string genderStr;
        string dateStr;

        getline(ss, id, ',');
        getline(ss, ageStr, ',');
        getline(ss, heightStr, ',');
        getline(ss, weightStr, ',');
        getline(ss, genderStr, ',');
        getline(ss, dateStr, ',');

        if (id == userID) {
            return stod(weightStr);
        }
    }

    return 0.0;
}

double Profile::getCurrentWeight(const string& userID) {
    return getWeight(userID);
}

double Profile::getHeight(const string& userID) {
    int age;
    double height, weight;
    string gender, date;

    if (loadProfile(userID, age, height, weight, gender, date))
        return height;

    return 0.0;
}

int Profile::getAge(const string& userID) {
    int age;
    double height, weight;
    string gender, date;

    if (loadProfile(userID, age, height, weight, gender, date))
        return age;

    return 0;
}

string Profile::getGender(const string& userID) {
    int age;
    double height, weight;
    string gender, date;

    if (loadProfile(userID, age, height, weight, gender, date))
        return gender;

    return "";
}


void Profile::displayMeasurements(const string& userID) {
    int age;
    double height, weight;
    string gender, date, firstName, lastName;
    Buddyz login;
    login.getUserName(userID, firstName, lastName);

    if (loadProfile(userID, age, height, weight, gender, date)) {
        setColor(YELLOW);
        cout << "\n--- Profile ---\n";
        cout << "User ID: " << userID << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " in\n";
        cout << "Weight: " << weight << " lbs\n";
        cout << "Gender: " << gender << endl;
        cout << "Last Updated: " << date << endl;
    } else {
        setColor(RED);
        cout << "Profile not found.\n";
    }
}