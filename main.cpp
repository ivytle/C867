//
//  main.cpp
//  C867 PA Ivy Le
//
//  Created by Ivy Le on 11/28/23.
//

#include "roster.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int ROSTERSIZE = 5;
const int DATASIZE = 9;
const string studentData[ROSTERSIZE] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ivy  ,Le    ,xxxx@wgu.edu,23,24,40,45,SOFTWARE"
};

void F1(){
    cout << "Course Name: C867" << endl;
    cout << "Progamming Language: C++" << endl;
    cout << "Student ID: 010681661" << endl;
    cout << "Name: Ivy Le" << endl;
}

DegreeProgram stoDegree(string str){
    if(str == "SECURITY"){
        return SECURITY;
    } else if (str == "NETWORK") {
        return NETWORK;
    } else if (str == "SOFTWARE"){
        return SOFTWARE;
    } else {
        return UNDECLARED;
    }
}

int main(){
    cout << endl;
    F1();
    Roster roster;

    for(int i = 0; i < ROSTERSIZE; i++){
        DegreeProgram degreeProgram;
        stringstream ss(studentData[i]);
        string str;
        string dataArr[DATASIZE];

        int j = 0;
        while (getline(ss, str, ','))
        {
            dataArr[j] = str;
            j += 1;
        }

        degreeProgram = stoDegree(dataArr[8]);
        roster.add(dataArr[0], dataArr[1], dataArr[2], dataArr[3], stoi(dataArr[4]), stoi(dataArr[5]), stoi(dataArr[6]), stoi(dataArr[7]), degreeProgram);
    }
    
    cout << endl;
    roster.printAll();
    cout << endl;
    roster.printInvalidEmails();
    cout << endl;

    for(int i = 0; i < ROSTERSIZE; i++){
        roster.printAverageDaysInCourse(roster.access_ID(i));
    }
    cout << endl;

    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    roster.remove("A3");
    cout << endl;

    roster.printAll();
    cout << endl;

    roster.remove("A3");
}
