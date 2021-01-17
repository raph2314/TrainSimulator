//
// Created by Raphael Lopez on 2021-01-14.
//

#ifndef TRAINSIMULATION_TRACKCOMPONENT_H
#define TRAINSIMULATION_TRACKCOMPONENT_H

#include <list>
#include <vector>

using std::vector;
using std::list;


class TrackComponent {
public:
    explicit TrackComponent(int col);

    virtual void insertComponent(vector<list<TrackComponent*>> *graph, TrackComponent* currNode) = 0;
    int getTrackComponentID() const;
    int getTrackComponentCol() const;

protected:
    static int nextID;
    int trackComponentID;
    int trackComponentCol;
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
