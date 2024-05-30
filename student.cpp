//
//  student.cpp
//  C867 PA Ivy Le
//
//  Created by Ivy Le on 11/30/23.
// Create each of the following functions in the Student class:
//
//      A) accessor (i.e., getter) for each instance variable from part D1
//      B) mutator (i.e., setter) for each instance variable from part D1
//      C) All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
//      D) Constructor using all of the input parameters provided in the table
//      E) Print() to print specific student data

#include "student.hpp"
#include <iostream>
#include <string>

using namespace std;
//constructor
Student::Student(string studentID_, string firstName_, string lastName_, string emailAddreess_, int age_, int daysUntilComplete_[3], DegreeProgram degreeProgram_){
    studentID = studentID_;
    firstName = firstName_;
    lastName = lastName_;
    emailAddress = emailAddreess_;
    age = age_;
    for (int i = 0; i < 3; i++){
        daysUntilComplete[i] = daysUntilComplete_[i];
    }
    degreeProgram = degreeProgram_;
}
//destructor
Student::~Student(){
}

//
string Student::access_studentID(){
    return studentID;
}

string Student::access_firstName(){
    return firstName;
}

string Student::access_lastName(){
    return lastName;
}

string Student::access_emailAddress(){
    return emailAddress;
}

int Student::access_age(){
    return age;
}

int* Student::access_daysUntilComplete(){
    return daysUntilComplete;
}

DegreeProgram Student::access_degreeProgram(){
    return degreeProgram;
}

string Student::access_degreeProgram_asString(){
    if (degreeProgram == SECURITY)
    {
        return "SECURITY";
    }
    else if (degreeProgram == NETWORK)
    {
        return "NETWORK";
    }
    else if (degreeProgram == SOFTWARE)
    {
        return "SOFTWARE";
    }
    else
    {
        return "UNDECLARED";
    }
}

void Student::set_studentID(string ID){
    studentID = ID;
}

void Student::set_firstName(string Name){
    firstName = Name;
}

void Student::set_lastName(string Name){
    lastName = Name;
}

void Student::set_emailAddress(string emailAddress_){
    emailAddress = emailAddress_;
}

void Student::set_age(int age_){
    age = age_;
}

//loads all three indexs
void Student::set_daysUntilComplete(int* days){
    //3 bc 3 courses
    for (int i = 0; i < 3; i++){
        daysUntilComplete[i] = days[i];
    }
}

void Student::set_degreeProgram(DegreeProgram dp){
    degreeProgram = dp;
}

void Student::print(){
    cout << access_studentID() << "\t"
        << "First Name: " << access_firstName() << "\t"
        << "Last Name: " << access_lastName() << "\t"
        << "Age: " << access_age() << "\t"
        << "daysInCourse: {" << access_daysUntilComplete()[0] << ", "
        << access_daysUntilComplete()[1] << ", "
        << access_daysUntilComplete()[2] << "}\t"
        << "Degree Program: " << access_degreeProgram_asString() << "." << endl;
}
