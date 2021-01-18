//
// Created by Raphael Lopez on 2021-01-17.
//

#ifndef TRAINSIMULATION_TRAIN_H
#define TRAINSIMULATION_TRAIN_H

#include <vector>
#include <list>

#include "TrackComponent.h"

using std::vector;
using std::list;

class Train {
public:
    Train(int locationID, char direction);

private:
    int trainID;
    int locationID;
    char direction;
};

class TrainController {
public:
    TrainController(vector<list<struct TrackComponent*>> *graph, Train* train);

};


#endif //TRAINSIMULATION_TRAIN_H
