//
//  roster.cpp
//  C867 PA Ivy Le
//
//  Created by Ivy Le on 11/30/23.
//
#include <iostream>

#include "roster.hpp"

#include <string>

using namespace std;

Roster::Roster(){
}

Roster::~Roster(){
    for (int i = 0; i < roster_len; i++)
    {
        delete classRoster[i];
        classRoster[i] = nullptr;
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int cDays[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    for (int i = 0; i < roster_len; i++)
    {
        if (classRoster[i] == nullptr){
            classRoster[i] = new Student(studentID, firstName, lastName, emailAddress, age, cDays, degreeProgram);
            break;
        }
    }
}

void Roster::remove(string studentID){
    bool flag = true;
    for(int i = 0; i < roster_len; i++){
        if (classRoster[i] == nullptr){
            continue;
        }

        if (classRoster[i]->access_studentID() == studentID){
            delete classRoster[i];
            classRoster[i] = nullptr;
            flag = false;
        }
    }
    if(flag){
        cout << "Error: No Sudent With " << studentID << " Found." << endl;
    }
}

void Roster::printAll(){
    for (int i = 0; i < roster_len; i++){
        if (classRoster[i] != nullptr){
            classRoster[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i < roster_len; i++)
    {
        if (classRoster[i] == nullptr)
        {
            continue;
        }
        if (classRoster[i]->access_studentID() == studentID){
            int sum = 0;
            // j < 3 bc 3 courses
            sum += classRoster[i]->access_daysUntilComplete()[0];
            sum += classRoster[i]->access_daysUntilComplete()[1];
            sum += classRoster[i]->access_daysUntilComplete()[2];
            sum /= 3;
            cout << "Student " << studentID << " average days in course = " << sum << endl;
            break;
        }
    }
}

void Roster::printInvalidEmails(){
    for (int i = 0; i < roster_len; i++)
    {
        if(classRoster[i]->access_emailAddress().find("@") == string::npos){
            cout << classRoster[i]->access_emailAddress() << endl;
        }
        else if (classRoster[i]->access_emailAddress().find(" ") == string::npos){
            cout << classRoster[i]->access_emailAddress() << endl;
        }
        else if (classRoster[i]->access_emailAddress().find(".") == string::npos){
            cout << classRoster[i]->access_emailAddress() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram DegreeProgram){
    for (int i = 0; i < roster_len; i++){
        if(classRoster[i]->access_degreeProgram() == DegreeProgram){
            classRoster[i]->print();
        }
    }
}

string Roster::access_ID(int index){
    return classRoster[index]->access_studentID();
}
