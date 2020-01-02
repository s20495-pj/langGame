#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cassert>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include "Scorer.h"
#include "Game.h"

using namespace std;

int main() {

    Scorer scorer;
    Game game;


   // game.readRules();
    //game.prepareRoundOneAndTwo();
   //  game.prepareRoundThree();
  //   game.prepareRoundFour();
   //  game.prepareRoundFive();
        game.playGame();
}