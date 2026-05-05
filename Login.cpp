#include "Login.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

bool Login::login(string& userID) {
    string password;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Enter User ID: ";
        cin >> userID;

        cout << "Enter Password: ";
        cin >> password;

        if (validateUser(userID, password)) {
            cout << "Login successful!\n";
            return true;
        }

        attempts++;

        cout << "Invalid credentials.\n";
        cout << "Attempts remaining: " << (3 - attempts) << "\n";
    }

    cout << "Too many failed attempts. Exiting...\n";

    cout << "Press ENTER to continue...";
    cin.ignore();
    cin.get();

    return false;
}

bool Login::createAccount(string& userID) {
    string password, firstName, lastName, email, phone, dateCreated, caloricGoal;

    cout << "Enter New User ID: ";
    cin >> userID;

    if (userExists(userID)) {
        cout << "User already exists.\n";
        return false;
    }

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Phone: ";
    cin >> phone;

    dateCreated = getCurrentDate();

    cout << "Choose a Caloric Goal: \n"
         << "1. Maintain\n"
         << "2. Lose Weight\n"
         << "3. Gain Muscle\n";

    cin >> caloricGoal;

    if (caloricGoal == "1") caloricGoal = "Maintain";
    else if (caloricGoal == "2") caloricGoal = "Lose Weight";
    else if (caloricGoal == "3") caloricGoal = "Gain Muscle";
    else caloricGoal = "Maintain";

    addUserToFile(userID, password, firstName, lastName, email, phone, dateCreated, caloricGoal);

    cout << "Account created successfully!\n";
    return true;
}

bool Login::validateUser(const string& userID, const string& password) {
    ifstream file("data/Users.csv");

    if (!file.is_open()) {
        cout << "Error opening users file.\n";
        return false;
    }

    string line;

    while (getline(file, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);

        string storedID = line.substr(0, p1);
        string storedPassword = line.substr(p1 + 1, p2 - p1 - 1);

        if (storedID == userID && storedPassword == password) {
            return true;
        }
    }

    return false;
}

bool Login::userExists(const string& userID) {
    ifstream file("data/Users.csv");

    if (!file.is_open()) return false;

    string line;

    while (getline(file, line)) {
        string storedID = line.substr(0, line.find(','));
        if (storedID == userID) return true;
    }

    return false;
}

void Login::addUserToFile(
    const string& userID,
    const string& password,
    const string& firstName,
    const string& lastName,
    const string& email,
    const string& phone,
    const string& dateCreated,
    const string& caloricGoal
) {
    ofstream outFile("data/Users.csv", ios::app);

    if (outFile.is_open()) {
        outFile << userID << "," << password << "," << firstName << "," << lastName << "," << email << "," << phone << "," << dateCreated << "," << caloricGoal << endl;

        outFile.close();
        cout << "User account created successfully!" << endl;
    } 
    else {
        cerr << "Error opening file for writing." << endl;
    }
}