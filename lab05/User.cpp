//
// Created by Boti on 11/6/2023.
//

#include "User.h"

User::User(const string &name) {
    id = counter;
    this->name = name;
}

int User::getId() const {
    return id;
}

const string &User::getName() const {
    return name;
}

void User::addScore(const string &quizName, double score) {
    scores[quizName] = score;
}

double User::getScore(const string &quizName) const {
    return scores.at(quizName);
}

void User::print(ostream &os) const {
    os << "User ID: " << id << endl;
    os << "Name: " << name << endl;
    os << "Scores: " << endl;
    for(const auto& entry : scores){
        os << " " << entry.first << ": " << entry.second << endl;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    user.print(os);
    return os;
}
