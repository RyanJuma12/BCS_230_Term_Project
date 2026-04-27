cmake_minimum_required(VERSION 4.1)
project(BCS_230_Term_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(BCS_230_Term_Project main.cpp
        Profile.h
        Nutrition.h
        Workout.h
        Tracker.h
        FileManager.h)
