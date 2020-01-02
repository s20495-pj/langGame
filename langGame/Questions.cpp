//
// Created by michal on 28.12.2019.
//

#include "Questions.h"

#include <random>
#include <utility>
#include <vector>
#include <algorithm>

Questions::Questions(string question, string answerOne, string answerTwo,
                     string answerThree) : question(std::move(question)), answerOne(std::move(answerOne)), answerTwo(std::move(answerTwo)),
                                           answerThree(std::move(answerThree)) {
//    std::vector<string> kutas;
//    kutas.push_back(answerOne);
//    kutas.push_back(answerTwo);
//    kutas.push_back(answerThree);
//    shuffle(kutas.begin(), kutas.end(), std::mt19937(std::random_device()()));
//
//    this->answerThree= kutas[0];
//    this->answerOne= kutas[2];
//    this->answerTwo= kutas[1];


}

Questions::Questions() {

}



