//
// Created by Boti on 10/23/2023.
//


#ifndef CPP_2022_QUESTION_H
#define CPP_2022_QUESTION_H

#include <string>
#include <vector>
#include "Answer.h"

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answers;
public:
    Question() = default;

    const string &getText() const {
        return text;
    }

    const vector<Answer> &getAnswers() const {
        return answers;
    }

    void setText(const string &text) {
        Question::text = text;
    }

    void setAnswers(const vector<Answer> &answers) {
        Question::answers = answers;
    }
};
#endif //CPP_2022_QUESTION_H
