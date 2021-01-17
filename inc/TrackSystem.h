//
// Created by Raphael Lopez on 2021-01-11.
//

#ifndef TRAINSIMULATION_TRACKSYSTEM_H
#define TRAINSIMULATION_TRACKSYSTEM_H

#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <fstream>

#include "TrackComponent.h"

enum graphFlags {
    FIRSTCHAR       = 1,
    SKIPJUNCTION    = 2
};

class TrackSystem {
public:
    explicit TrackSystem(std::string& fName);

    bool buildTrackFromFile();

    void selectPrevParent(TrackComponent** prevParent);
    void selectParent(TrackComponent** parent, TrackComponent** prevParent);

    void printTrackSystem() const;

private:
    std::string fileName;
    std::stack<Junction*> junctions;

    // Track any junctions that were skipped to form track loops
    Junction* skippedJunction;

    int graphState;
    std::vector<std::list<TrackComponent*>> graph;
};

#endif //TRAINSIMULATION_TRACKSYSTEM_H
