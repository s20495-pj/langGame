//
// Created by michal on 29.12.2019.
//

#include <iostream>
#include "Game.h"
#include <fstream>
#include <random>
#include <string>
#include <cassert>
#include <ctime>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string finishInformation = "\n Koniec gry, wykorzystales wszystkie skuchy. Twoj wynik to : ";

void Game::readRules() {

    ifstream file("/home/michal/CLionProjects/langGame/rules.txt");

    while (!file.eof()) { // To get you all the lines.
        getline(file, rules);
        cout << rules << "\n";
    }
    file.close();
    cout << "\n Let's play the game. \n";
}

void Game::prepareRoundOneAndTwo() {

    ifstream fileRoundOneAndTwo("/home/michal/CLionProjects/langGame/roundOneAndTwo.txt");
    if (fileRoundOneAndTwo.is_open()) {

        for (int i = 0; i < 40; ++i) {
            fileRoundOneAndTwo >> myArrayRoundOneAndTwo[i];
        }
    }
    fileRoundOneAndTwo.close();
}

void Game::prepareRoundThree() {

    ifstream fileRoundThree("/home/michal/CLionProjects/langGame/roundThree.txt");

    while (getline(fileRoundThree, line)) {
        thirdRoundSentences.push_back(line);
    }
    fileRoundThree.close();
}

void Game::prepareRoundFour() {

    ifstream fileRoundFour("/home/michal/CLionProjects/langGame/roundFour.txt");

    while (!fileRoundFour.eof()) {
        for (int i = 0; i < 30; ++i) {
            getline(fileRoundFour, question);
            getline(fileRoundFour, answerOne);
            getline(fileRoundFour, answerTwo);
            getline(fileRoundFour, answerThree);
            fourthRoundSentences.push_back(Questions(question, answerOne, answerTwo, answerThree));
            //   myArrayRoundFour[i];
        }
    }
}

void Game::prepareRoundFive() {

    ifstream fileRoundFive("/home/michal/CLionProjects/langGame/roundFive.txt");
    if (fileRoundFive.is_open()) {

        for (int i = 0; i < 40; ++i) {
            fileRoundFive >> myArrayRoundFive[i];
        }
    }
    fileRoundFive.close();
}

void Game::playGame() {

    Game::readRules();

    switch (scorer.getPoints()) {
//        case 0:
//            Game::prepareRoundOneAndTwo();
//            while (scorer.getPoints() < 11 && scorer.getMinusPoints() < 11) {
//                if (scorer.getMinusPoints() == 10) {
//                    cout << finishInformation << scorer.getPoints();
//                    break;
//                }
//                Game::roundOne();
//            }
//        case 10:
//            Game::prepareRoundOneAndTwo();
//            while (scorer.getPoints() < 21 && scorer.getMinusPoints() < 11) {
//                if (scorer.getMinusPoints() == 10) {
//                    cout << finishInformation << scorer.getPoints();
//                    break;
//                }
//                Game::roundTwo();
//            }
//        case 20:
//            Game::prepareRoundThree();
//            while (scorer.getPoints() < 31 && scorer.getMinusPoints() < 11) {
//                if (scorer.getMinusPoints() == 101) {
//                    cout << finishInformation << scorer.getPoints();
//                    break;
//                }
//                Game::roundThree();
//            }
//        case 30:
//            Game::prepareRoundFour();
//            while (scorer.getPoints() < 41 && scorer.getMinusPoints() < 11) {
//                if (scorer.getMinusPoints() == 10) {
//                    cout << finishInformation << scorer.getPoints();
//                    break;
//                }
//                Game::roundFour();
//            }
        case 0:
            Game::prepareRoundFive();
            while (scorer.getPoints() < 51 && scorer.getMinusPoints() < 131) {
                if (scorer.getMinusPoints() == 103) {
                    cout << finishInformation << scorer.getPoints();
                    break;
                }
                if (scorer.getPoints() == 60) {
                    cout << "Gratulacje, udalo Ci sie ukonczyc gre! ";
                }
                Game::roundFive();
            }
    }
}


void Game::roundOne() {
    srand(time(0));
    random = (rand() % 40) + 1;
    string word = myArrayRoundOneAndTwo[random];
    --random;
    string translationWord = myArrayRoundOneAndTwo[random];
    if (random % 2 == 1) {
        random++;
    } else if (random % 2 == 0) {
        cout << "\n Write translation of word below " << '\n' << word << endl;

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
    string word = myArrayRoundOneAndTwo[random];
    ++random;
    string translationWord = myArrayRoundOneAndTwo[random];

    if (random % 2 == 0) {
        random--;
    } else if (random % 2 == 1) {

        cout << "\nWrite translation of word below " << '\n' << word << endl;
        cin >> typeWord;

        if (typeWord == translationWord) {
            scorer.addPoints();
        } else {
            scorer.oddPoints();
        }
    }
}

void Game::roundThree() {
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
    arrayWithOneLineStrings.push_back(wholeSentenceLine); //add last left word to vector

    srand(time(0));
    random = rand() % arrayWithOneLineStrings.size();

    token = arrayWithOneLineStrings[random];

    if (chosenLine.find(token) != string::npos) {
        chosenLine.replace(chosenLine.find(token), token.size(), "....");
    }

    cout << "\n" << chosenLine << endl;
    cout << "\n" << token << endl;
    cin >> typeWord;
    arrayWithOneLineStrings.clear(); //clear array after answer, avoid adding more than one sentence to vector

    if (typeWord == token) {
        scorer.addPoints();
    } else {
        scorer.oddPoints();
        cout << "\n poprawny wyraz to : " << token;
    }
}

void Game::roundFour() {
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
        cout << "\n poprawny wyraz to : " << answerOne;
    }
}

void Game::roundFive() {
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
