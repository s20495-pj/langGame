//
// Created by michal on 29.12.2019.
//

#include <iostream>
#include "Game.h"
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string finishInformation = "\n Game over. Try again later. Your final score is : ";

void Game::readRules() {

    ifstream fileRules("../../langGame/langGame/rules.txt");

    while (!fileRules.eof()) { // To get you all the lines.
        getline(fileRules, rules);
        cout << rules << "\n";
    }
    fileRules.close();
    cout << "\n Let's play the game. \n";
}

void Game::prepareRoundOneAndTwo() {

    ifstream fileRoundOneAndTwo("../../langGame/langGame/roundOneAndTwo.txt");
    if (fileRoundOneAndTwo.is_open()) {

        for (int i = 0; i < 40; ++i) {
            fileRoundOneAndTwo >> myArrayRoundOneAndTwo[i];
        }
    }
    fileRoundOneAndTwo.close();
}

void Game::prepareRoundThree() {

    ifstream fileRoundThree("../../langGame/langGame/roundThree.txt");

    while (getline(fileRoundThree, line)) {
        thirdRoundSentences.push_back(line);
    }
    fileRoundThree.close();
}

void Game::prepareRoundFour() {

    ifstream fileRoundFour("../../langGame/langGame/roundFour.txt");

    while (!fileRoundFour.eof()) {
        for (int i = 0; i < 30; ++i) {
            getline(fileRoundFour, question);
            getline(fileRoundFour, answerOne);
            getline(fileRoundFour, answerTwo);
            getline(fileRoundFour, answerThree);
            fourthRoundSentences.push_back(Questions(question, answerOne, answerTwo, answerThree));
        }
    }
    fileRoundFour.close();
}

void Game::prepareRoundFive() {

    ifstream fileRoundFive("../../langGame/langGame/roundFive.txt");
    if (fileRoundFive.is_open()) {

        for (int i = 0; i < 40; ++i) {
            fileRoundFive >> myArrayRoundFive[i];
        }
    }
    fileRoundFive.close();
}

void Game::roundOne() {

    if (!preparedRoundOneAndTwo) {
        prepareRoundOneAndTwo();
    }
    srand(time(0));
    random = (rand() % 40) + 1;
    word = myArrayRoundOneAndTwo[random];
    --random;
    translationWord = myArrayRoundOneAndTwo[random];
    if (random % 2 == 1) {
        random++;
    } else if (random % 2 == 0) {
        cout << "\n Write translation of word below:  " << '\n' << word << "\n";

        cin >> typeWord;
        if (typeWord == translationWord) {
            scorer.addPoints();
        } else {
            scorer.oddPoints();
        }
    }
}

void Game::roundTwo() {
    srand(time(0)
    );
    random = (rand() % 40) + 1;
    word = myArrayRoundOneAndTwo[random];
    ++random;
    translationWord = myArrayRoundOneAndTwo[random];

    if (random % 2 == 0) {
        random--;
    } else if (random % 2 == 1) {

        cout << "\nWrite translation of word below:  " << '\n' << word << "\n";
        cin >> typeWord;

        if (typeWord == translationWord) {
            scorer.addPoints();
        } else {
            scorer.oddPoints();
        }
    }
}

void Game::roundThree() {
    if (!preparedRoundThree) {
        prepareRoundThree();
    }
    srand(time(0));
    random = rand() % thirdRoundSentences.size();

    wholeSentenceLine = thirdRoundSentences[random];
    chosenLine = wholeSentenceLine;
    delimiter = " ";

    size_t pos = 0; //sizeOf

    while ((pos = wholeSentenceLine.find(delimiter)) != std::string::npos) { //npos = no position
        token = wholeSentenceLine.substr(0, pos);
        wholeSentenceLine.erase(0, pos + delimiter.length());  //erase word one by one from whole sentence
        arrayWithOneLineStrings.push_back(token); //add to vector
    }
    wholeSentenceLine.pop_back(); //removing default \r from end of last word
    arrayWithOneLineStrings.push_back(wholeSentenceLine); //add last left word to vector

    srand(time(0));
    random = rand() % arrayWithOneLineStrings.size();

    token = arrayWithOneLineStrings[random];

    if (chosenLine.find(token) != string::npos) {
        chosenLine.replace(chosenLine.find(token), token.size(), "...");
    }

    cout << "\n" << chosenLine << "\n";
    cin >> typeWord;
    arrayWithOneLineStrings.clear(); //clear array after answer, avoid adding more than one sentence to vector

    if (typeWord == token) {
        scorer.addPoints();
    } else {
        scorer.oddPoints();
        cout << "\n Right answer is  : " << token << "\n";
    }
}

void Game::roundFour() {
    if (!preparedRoundFour) {
        prepareRoundFour();
    }
    srand(time(0));
    random = rand() % fourthRoundSentences.size();

    Questions chosenQuestion(question, answerOne, answerTwo, answerThree);
    chosenQuestion = fourthRoundSentences[random];

    answers.push_back(chosenQuestion.answerOne);
    answers.push_back(chosenQuestion.answerTwo);
    answers.push_back(chosenQuestion.answerThree);

    random_shuffle(answers.begin(), answers.end());

    cout << "\n" << chosenQuestion.question << "\n";

    //print strings from vector
    for (vector<string>::const_iterator i = answers.begin(); i != answers.end(); ++i) {
        cout << *i << ' ' << endl;
    }
    answers.clear();

    cin >> typeWord;

    if (typeWord == chosenQuestion.answerOne) {
        scorer.addPoints();
    } else {
        scorer.oddPoints();
        cout << "\n Right answer is  : " << answerOne << "\n";
    }
}

void Game::roundFive() {
    if (!preparedRoundFive) {
        prepareRoundFive();
    }
    srand(time(0));
    random = (rand() % 40) + 1;

    word = myArrayRoundFive[random];
    translationWord = myArrayRoundFive[random];

    if (random % 2 == 0) {
        cout << "\nWrite opposite word below   " << '\n' << word << endl;
        cin >> typeWord;

        if (typeWord == myArrayRoundFive[++random]) {
            scorer.addPoints();
        } else {
            scorer.oddPoints();
        }
    } else if (random % 2 == 1 || random == 40) {

        cout << "\nWrite opposite word below   " << '\n' << word << endl;
        cin >> typeWord;
        if (typeWord == myArrayRoundFive[--random]) {
            scorer.addPoints();
        } else {
            scorer.oddPoints();
        }
    }
}

void Game::playGame() {

    Game::readRules();

    while (true) {

        if (scorer.getPoints() == 50) {
            cout << "\nCongratulations! You finished the game  " << endl;
            return;
        }
        if (scorer.getMinusPoints() == 10) {
            cout << finishInformation << scorer.getPoints();
            return;
        }
        switch (scorer.getPoints() / 10) {

            case 0:
                roundOne();
                break;
            case 1:
                roundTwo();
                break;
            case 2:
                roundThree();
                break;
            case 3:
                roundFour();
                break;
            case 4:
                roundFive();
                break;
        }
    }
}
