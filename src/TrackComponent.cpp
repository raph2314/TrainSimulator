//
// Created by Raphael Lopez on 2021-01-14.
//

#include "TrackComponent.h"


// Initialize global ID tracker
int TrackComponent::nextID = 0;

/*-----------------------------------------------------*/
/* TrackComponent as base class
 *-----------------------------------------------------*/
TrackComponent::TrackComponent(int col) : trackComponentCol(col) {
    trackComponentID = nextID++;
}

int TrackComponent::getTrackComponentID() const {
    return trackComponentID;
}

int TrackComponent::getTrackComponentCol() const {
    return trackComponentCol;
}

/*-----------------------------------------------------*/
/* Track ('-') component
 *-----------------------------------------------------*/
Track::Track(int col) : TrackComponent(col) {

}

void Track::insertComponent(vector<list<TrackComponent*>> *graph, TrackComponent* currNode) {
    // Insert track
    std::list<TrackComponent *> newList(1, this);
    graph->push_back(newList);

    // Add edges between track and its parent
    graph->at(currNode->getTrackComponentID()).push_back(this);
    graph->at(this->getTrackComponentID()).push_back(currNode);
}

/*-----------------------------------------------------*/
/* Junction ('=') component
 *-----------------------------------------------------*/
Junction::Junction(int col) : TrackComponent(col) {

}

void Junction::insertComponent(vector<list<TrackComponent*>> *graph, TrackComponent* currNode) {
    // Insert junction
    std::list<TrackComponent*> newList(1, this);
    graph->push_back(newList);

    // Add edges between junction and its parents
    graph->at(currNode->getTrackComponentID()).push_back(this);
    graph->at(this->getTrackComponentID()).push_back(currNode);
}