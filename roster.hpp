//
//  roster.hpp
//  C867 PA Ivy Le
//
//  Created by Ivy Le on 11/30/23.
//
// include student header file
#ifndef roster_hpp
#define roster_hpp
#include <stdio.h>
#endif /* roster_hpp */

#pragma once

#include "student.hpp"

using namespace std;

class Roster{
    private:
        int roster_len = 5;
        Student* classRoster[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    public:
        Roster();
        ~Roster();

        void add(string, string, string, string, int, int, int, int, DegreeProgram);
        void remove(string);
        void printAll();
        void printAverageDaysInCourse(string);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram);

        string access_ID(int);
};


