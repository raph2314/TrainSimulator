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

#include "TrackBuilder.h"
#include "TrackComponent.h"
#include "Train.h"

using std::list;
using std::vector;

enum graphFlags {
    FIRSTCHAR       = 1,
    SKIPJUNCTION    = 2
};


class TrackSystem {
public:
    explicit TrackSystem(std::string& fName);

    vector<list<TrackComponent*>>* getGraph();
    Train* getTrain() const;

    // Creates a graph based on a trackConfig file
    bool buildTrackFromFile();

    // Called whenever a new line is being processed to know where to branch from
    void selectPrevParent(TrackComponent** prevParent);
    void selectParent(TrackComponent** parent, TrackComponent** prevParent);

    // Used for debugging
    void printTrackSystem() const;

private:
    std::string fileName;  // File where trackConfig is stored.

    std::stack<Junction*> junctions;  // Track junctions for branching new lanes
    Junction* skippedJunction;  // Track any junctions that were skipped to form track loops

    int graphState;  // Track flags defined in "graphFlags"
    vector<list<TrackComponent*>> graph;  // Adjacency list representation of track components

    Train* train;
};

#endif //TRAINSIMULATION_TRACKSYSTEM_H
