//
// Created by michal on 29.12.2019.
//

#ifndef LANGGAME_GAME_H
#define LANGGAME_GAME_H

#include <vector>
#include "Questions.h"
#include "Scorer.h"

using namespace std;

class Game {

public:
    string myArrayRoundOneAndTwo[40];
    string myArrayRoundFive[40];
    string line;
    string rules;

    string typeWord;
    string token;

    string question;
    string answerOne;
    string answerTwo;
    string answerThree;

    string chosenLine;
    string wholeSentenceLine;
    string delimiter;

    string word;
    string translationWord;

    vector<Questions> fourthRoundSentences;
    vector<string> thirdRoundSentences;
    vector<string> arrayWithOneLineStrings;
    vector<string> answers;

    Scorer scorer;

    int random;

    bool preparedRoundOne;
    bool preparedRoundTwo;
    bool preparedRoundThree;
    bool preparedRoundFour;
    bool preparedRoundFive;

    void readRules();
    void prepareRoundOneAndTwo();
    void prepareRoundThree();
    void prepareRoundFour();
    void prepareRoundFive();
    void playGame();

    void roundOne();
    void roundTwo();
    void roundThree();
    void roundFour();
    void roundFive();
};

#endif //LANGGAME_GAME_H
