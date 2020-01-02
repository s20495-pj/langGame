//
// Created by michal on 28.12.2019.
//

#ifndef LANGGAME_QUESTIONS_H
#define LANGGAME_QUESTIONS_H

#include <string>

using namespace std;

class Questions {

public:

    string question;
    string answerOne;
    string answerTwo;
    string answerThree;

    Questions(string question, string answerOne, string answerTwo, string answerThree);
};


#endif //LANGGAME_QUESTIONS_H
