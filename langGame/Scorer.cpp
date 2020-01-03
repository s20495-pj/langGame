//
// Created by michal on 28.12.2019.
//
#include <iostream>
#include "Scorer.h"
using namespace std;

int Scorer::addPoints() {
    points++;
    cout <<"\n Dobrze! \n Twoja liczba punktow to: " << getPoints()<< "\n";
    return points;
}

int Scorer::oddPoints() {
    minusPoints++;
    cout << "\n Zle! \n Twoja liczba nieudanych prob to: " << getMinusPoints()<< "\n";
    return minusPoints;
}

Scorer::Scorer() = default;

int Scorer::getPoints() {
    return points;
}

int Scorer::getMinusPoints() {
    return minusPoints;
}

void Scorer::setPoints(int points) {
    Scorer::points = points;
}

void Scorer::setMinusPoints(int minusPoints) {
    Scorer::minusPoints = minusPoints;
}


