//
// Created by Boti on 10/23/2023.
//

#ifndef CPP_2022_ANSWER_H
#define CPP_2022_ANSWER_H

#include "string"

using namespace std;

class Answer{
private:
    string text;
    bool correct;
public:
    Answer(string text = "", bool correct = false):text(text), correct(correct){}
    const string &getText() const {
        return text;
    }

    void setText(const string &text) {
        Answer::text = text;
    }

    void setCorrect(bool correct) {
        Answer::correct = correct;
    }
    bool isCorrect() const{
        return correct;
    }
};

#endif //CPP_2022_ANSWER_H
