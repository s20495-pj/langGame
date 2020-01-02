//
// Created by michal on 28.12.2019.
//

#ifndef LANGGAME_SCORER_H
#define LANGGAME_SCORER_H


class Scorer {

public :
    int points{};
    int minusPoints{};

    int addPoints();

    int oddPoints();

    int getPoints();

    int getMinusPoints();

    Scorer();

    void setPoints(int points);

    void setMinusPoints(int minusPoints);

};


#endif //LANGGAME_SCORER_H
