#include <iostream>
#include "Quiz.h"

using namespace std;

int main() {
    cout << "Hello, Lab_05" << endl;

    Quiz quiz("Quiz 1", "quiz.txt");
    cout << quiz.getNumQuestions() << endl;
    for(int i = 0; i < quiz.getNumQuestions(); ++i){
        cout << (i + 1) << '.' << quiz.getQuestion(i).getText() << endl;
        for(int j = 0; j < quiz.getQuestion(i).getAnswers().size(); ++j){
            cout << quiz.getQuestion(i).getAnswers()[j].getText() << " - " << quiz.getQuestion(i).getAnswers()[j].isCorrect() << endl;
        }
        cout << endl;
    }

    return 0;
}