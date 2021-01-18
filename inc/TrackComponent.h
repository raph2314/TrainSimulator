//
// Created by Raphael Lopez on 2021-01-14.
//

#ifndef TRAINSIMULATION_TRACKCOMPONENT_H
#define TRAINSIMULATION_TRACKCOMPONENT_H

#include <list>
#include <vector>


#include "TrackBuilder.h"
#include "Train.h"

using std::vector;
using std::list;


class TrackComponent {
public:
    explicit TrackComponent(int col);

    virtual void insertComponent(vector<list<TrackComponent*>> *graph, TrackComponent* currNode) = 0;

    // Accessors for edge assignments during graph construction
    int getTrackComponentID() const;
    int getTrackComponentCol() const;

    // Accessors for component customization during graph construction
    bool containsSignal() const;
    char getSignalEast() const;
    char getSignalWest() const;

    // Modifiers for train traversal
    void assignSignalEast(char state);
    void assignSignalWest(char state);

protected:
    static int nextID;
    int trackComponentID;
    int trackComponentCol;

    bool hasSignal, hasTrain;
    char signalEast, signalWest;

};

class Track : public TrackComponent {
public:
    explicit Track(int col);

    void insertComponent(vector<list<TrackComponent*>> *graph, TrackComponent* currNode) override;
};

class Junction : public TrackComponent {
public:
    explicit Junction(int col);

    void insertComponent(vector<list<TrackComponent*>> *graph, TrackComponent* currNode) override;
};

#endif //TRAINSIMULATION_TRACKCOMPONENT_H
