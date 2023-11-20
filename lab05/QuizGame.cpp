//
// Created by Boti on 11/6/2023.
//

#include <fstream>
#include "QuizGame.h"

void QuizGame::play() {
    ifstream quizFile("cpp1.txt");
    if(!quizFile.is_open()){
        cout << "Sikertelen file megnyitas!";
        return;
    }
    string line;
    string question;
    vector<string> answers;
    int correctAnswer = 0;
    while(getline(quizFile, line)){
        if(line[0] = 'Q'){
            question = line.substr(2);
            cout << "Q " << question << endl;
        }else if(line[0] == 'A'){
            string answer = line.substr(2);
            answers.push_back(answer);
        }else if(line[0] >= '1' && line[0] <= '9'){
            correctAnswer = line[0] - '1';
            for(int i = 0; i < answers.size(); ++i){
                cout << (i + 1) << " " << answers[i] << endl;
            }
            int userChoice;
            cout << "Valassz egy lehetoseget: ";
            cin >> userChoice;
            if(userChoice - 1 == correctAnswer){
                score += 1.0;
                cout << "Helyes valasz!";
            }
            else{
                cout << "Rossz valasz. A helyes valasz: " << answers[correctAnswer] << endl;

            }
            question.clear();
            answers.clear();
            correctAnswer = 0;
            user.addScore(quiz.getName(), score);
        }
    }
}
