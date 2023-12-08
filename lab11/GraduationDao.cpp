//
// Created by Boti on 12/4/2023.
//

#include <fstream>
#include <sstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string firstName, lastName;
        ss >> id >> firstName >> lastName;

        Student student(id, firstName, lastName);

        if (students.find(id) == students.end()) {
            students.insert({student.getId(), student});
        } else {
            cerr << "Student with ID " << id << " already enrolled." << endl;
        }
    }
    file.close();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        int id;
        double grade;
        ss >> id >> grade;
        try{
            Student &student = students.at(id);
            student.addGrade(subject, grade);
        }catch(const out_of_range &ex){
            cerr << ex.what() << "for student with ID: " << id << endl;
        }
    }
    file.close();
}

void GraduationDao::computeAverage() {
    for(auto student : students){
        student.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for(const auto& student : students)
    {
        if(student.second.getAverage() != 0)
            count ++;
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    auto it = students.find(id);
    if(it != students.end()){
        return it->second;
    }
    else{
        throw out_of_range("Student not found!");
    }
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double total = 0.0;
    int count = 0;
    for(const auto &studentPair : students){
        const Student &student = studentPair.second;
        const map<string, double> &studentGrades = student.getGrades();
        auto it = studentGrades.find(subject);
        if(it != studentGrades.end()){
            total += it->second;
            count++;
        }
        else {
            cerr << "Subject not found for student with ID: " << student.getId() << endl;
        }
    }
    return count > 0 ? total / count : 0.0;
}
