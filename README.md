# BodyBuddy Fitness Tracker

BodyBuddy is a C++ console-based fitness tracking application designed to help users manage their fitness journey by tracking workouts, calorie intake, and body measurements. The project uses CSV files for persistent data storage and provides a simple user-friendly interface with colored console output and formatted menus.

---

## Features

### User Account System
- Create new user accounts
- Secure login system with password validation
- Failed login handling and input validation
- Personalized user greetings

### Profile Management
- Store and update:
  - Weight
  - Height
  - Age
  - Body measurements
- Track measurement history over time
- Maintenance calorie calculator

### Nutrition Tracking
- Log daily calorie intake
- Store nutrition logs in CSV files
- View calorie history
- Caloric goal tracking
- Encouraging messages displayed while viewing logs

### Workout Tracking
- Log workouts and exercise activity
- Save workout history to CSV files
- Track progress over time

### Console UI Improvements
- Colored console text output
- Improved formatting and readability
- Cleaner menus and user interaction

### File Management
- CSV-based persistent storage
- Improved file handling across all modules
- Shared global date utility
- Cross-system executable compatibility improvements

---

## Technologies Used

- **Language:** C++
- **IDE Support:** VS Code / CLion
- **Storage:** CSV Files
- **Compiler:** g++
- **Libraries:**
  - `<iostream>`
  - `<fstream>`
  - `<sstream>`
  - `<vector>`
  - `<windows.h>` (for console colors)

---

## Project Structure

```text
BodyBuddy/
│
├── BodyBuddy.cpp
├── Buddyz.cpp
├── Buddyz.h
├── Profile.cpp
├── Profile.h
├── Nutrition.cpp
├── Nutrition.h
├── Workout.cpp
├── Workout.h
├── Tracker.cpp
├── Tracker.h
├── Date.cpp
├── Date.h
├── ConsoleColors.cpp
├── ConsoleColors.h
│
Data/
├── Profile.csv
├── Nutrition.csv
├── Workouts.csv
└── Users.csv
 

```
# How to Build

## Using VS Code

Make sure you have:

- MSYS2 / MinGW installed
- `g++` configured in PATH

### Compile using:

```bash
g++ BodyBuddy.cpp Profile.cpp Nutrition.cpp Workout.cpp Tracker.cpp Login.cpp Date.cpp -o BodyBuddy.exe

```
# May 2026 Updates
- Added encouraging motivational messages
- Improved login validation and error handling
- Added colored console text
- Improved overall formatting
- Added maintenance calorie calculations
- Added weight tracking functionality
- Improved CSV file handling
- Added workout and nutrition logging
- Renamed project branding to BodyBuddy
- Added cross-system executable support
- Improved VS Code build configuration

# Future Improvements
Planned future updates include:
- Graphical User Interface (GUI)
- Better calorie analytics
- Workout recommendations
- Password encryption
- Expanded nutrition tracking
- Progress charts and reports
- Improved calorie log viewing system


