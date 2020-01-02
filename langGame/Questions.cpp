//
// Created by michal on 28.12.2019.
//

#include "Questions.h"


#include <utility>

Questions::Questions(string question, string answerOne, string answerTwo,
                     string answerThree) : question(std::move(question)), answerOne(std::move(answerOne)), answerTwo(std::move(answerTwo)),
                                           answerThree(std::move(answerThree)) {}

Questions::Questions() {}



