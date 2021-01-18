//
// Created by Raphael Lopez on 2021-01-17.
//

#include "Train.h"

Train::Train(int locationID, char direction) : trainID(0) {
    this->locationID = locationID;
    this->direction = direction;
}



TrainController::TrainController(vector<list<TrackComponent *>> *graph, Train * train) {

}


