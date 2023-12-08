//
// Created by Boti on 12/4/2023.
//

#include <fstream>
#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) : id(id), firstName(firstName),
                                                                            lastName(lastName) {}

int Student::getId() const {
    return id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::setId(int id) {
    Student::id = id;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) {
    if(grades.find(subject) != grades.end())
        return grades[subject];
    else{
        throw out_of_range("Subject not found!");
    }
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    if (grades.empty()) {
        average = 0.0;
        return;
    }

    bool allGradesAboveFive = true;
    for (const auto& grade : grades) {
        if (grade.second <= 5.0) {
            allGradesAboveFive = false;
            break;
        }
    }

    if (allGradesAboveFive) {
        double sum = 0.0;
        for (const auto& grade : grades) {
            sum += grade.second;
        }
        double calculatedAverage = sum / grades.size();

        if (calculatedAverage > 6.0) {
            average = calculatedAverage;
        } else {
            average = 0.0;
        }
    } else {
        average = 0.0;
    }
}


double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "ID: " << student.id << " Name: " << student.firstName << " " << student.lastName << " ";
    os << "Grades: ";
    for(const auto& grade : student.grades){
        cout << grade.first << ":" << grade.second <<"\t";
    }
}

