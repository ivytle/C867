//
//  student.hpp
//  C867 PA Ivy Le
//
//  Created by Ivy Le on 11/30/23.
//
#pragma once
#ifndef student_hpp
#define student_hpp

#include <stdio.h>

#endif /* student_hpp */

#include <iomanip>
#include <iostream>
#include "degree.h"
#include <string>


using namespace std;

class Student {
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysUntilComplete[3] = {189, 189, 189}; //change later
        DegreeProgram degreeProgram; //change later
    public:
        //constructor
        Student(string, string, string, string, int, int[], DegreeProgram);
        //destructor
        ~Student();

        //accessors
        string access_studentID();
        string access_firstName();
        string access_lastName();
        string access_emailAddress();
        int access_age();
        int* access_daysUntilComplete();
        DegreeProgram access_degreeProgram();
        string access_degreeProgram_asString();

        //mutator
        void set_studentID(string);
        void set_firstName(string);
        void set_lastName(string);
        void set_emailAddress(string);
        void set_age(int);
        void set_daysUntilComplete(int*);
        void set_degreeProgram(DegreeProgram);
        
        //print
        void print();
};


