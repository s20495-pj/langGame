//
// Created by michal on 28.12.2019.
//
#include <iostream>
#include "Scorer.h"
using namespace std;

int Scorer::addPoints() {
    points++;
    cout <<"\n Good Answer! \n Your number of points: " << getPoints()<< "\n";
    return points;
}

int Scorer::oddPoints() {
    minusPoints++;
    cout << "\n Wrong! \n Your number of failed attempts is: " << getMinusPoints()<< "\n";
    return minusPoints;
}

Scorer::Scorer() = default;

int Scorer::getPoints() {
    return points;
}

int Scorer::getMinusPoints() {
    return minusPoints;
}


