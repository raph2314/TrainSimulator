//
// Created by Raphael Lopez on 2021-01-11.
//

#include "TrackSystem.h"


TrackSystem::TrackSystem(std::string& fName) : fileName(fName), skippedJunction(nullptr), graphState(0) {

}

vector<list<TrackComponent*>>* TrackSystem::getGraph() { return &graph; };

Train* TrackSystem::getTrain() const { return train; };


bool TrackSystem::buildTrackFromFile() {
    // File and line handles for processing
    std::ifstream infile("./../" + fileName);
    std::string line;

    TrackComponent* parent;      // Track previously inserted component to assist in edge assignment
    TrackComponent* prevParent;  // Track previously inserted component when a Junction Skip occurs

    // Process each line in the file
    while(std::getline(infile, line)) {

        // Line empty:
        //        Skip most recent junction if any
        //        Otherwise create a new segment
        if(line.find_first_not_of(' ') == std::string::npos) {
            graphState ^= SKIPJUNCTION;
            selectPrevParent(&prevParent);
        }

        // Line non-empty:
        //        Branch from most recent junction if any
        //        Otherwise create a new segment
        else {
            selectParent(&parent, & prevParent);
        }

        int col = 0;  // Column tracking to close junction loops

        // Process each character in line
        for(auto c: line) {

            // No further processing for empty lines
            if(!(graphState & SKIPJUNCTION)) {

                // No further processing for new segment
                if(graphState & FIRSTCHAR) {
                    graphState ^= FIRSTCHAR;
                }

                else {
                    switch(c) {
                        case TRACK: {
                            auto *newTrack = new Track(col);
                            newTrack->insertComponent(&graph, parent);
                            parent = newTrack;
                            break;
                        }
                        case JUNCTION: {
                            auto* newJunction = new Junction(col);
                            newJunction->insertComponent(&graph, parent);
                            parent = newJunction;

                            // Track new junctions in junctions stack
                            junctions.push(newJunction);
                            break;
                        }
                        case TRAIN: {
                            train = new Train(parent->getTrackComponentID(), DIR_EAST);
                            break;
                        }
                        case SIGNAL_GREEN:
                            parent->assignSignalEast(SIGNAL_GREEN);
                            parent->assignSignalWest(SIGNAL_GREEN);
                            break;

                        default:
                            if(c == SPACING || c == NEWLANE || c == ENTER);  // Ignore characters
                            else
                                return false;  // Invalid character
                    }
                }


                // Check if column of skipped junction matches to close the loop
                if( (skippedJunction != nullptr) && (col == skippedJunction->getTrackComponentCol())) {
                    // Add edges to graph
                    graph.at(parent->getTrackComponentID()).push_back(skippedJunction);
                    graph.at(skippedJunction->getTrackComponentID()).push_back(parent);

                    skippedJunction = nullptr;  // Loop is closed; junction is no longer skipped
                }
            }
            col++;
        }
    }
    return true;
}

void TrackSystem::selectPrevParent(TrackComponent** prevParent) {
    // (Case: 1+ Junction): Skip last junction, so that parent is the second last junction
    if(junctions.size() > 1)  {
        skippedJunction = junctions.top();  // Store last junction to rejoin later
        junctions.pop();

        *prevParent = junctions.top();  // Branch from second last junction
        junctions.pop();
    }

    // (Case: 0 or 1 Junction): Parent is a new segment
    else {
        if(junctions.size() == 1) {
            skippedJunction = junctions.top(); // Store last junction to rejoin later
            junctions.pop();
        }

        graphState ^= FIRSTCHAR;

        *prevParent = new Track(0);
        std::list<TrackComponent*> newSegment(1, *prevParent);
        graph.push_back(newSegment);
    }
}

void TrackSystem::selectParent(TrackComponent** parent, TrackComponent** prevParent) {
    // (Case: Skip junction): Parent was found in the previous line
    if(graphState & SKIPJUNCTION) {
        *parent = *prevParent;
        graphState ^= SKIPJUNCTION;
    }

    // (Case: Branch from junction): Parent is the most recent junction
    else if(!junctions.empty()) {
        *parent = junctions.top();
        junctions.pop();
    }

    // (Case: No junctions): Parent is a new segment
    else {
        graphState ^= FIRSTCHAR;

        *parent = new Track(0);
        std::list<TrackComponent*> newSegment(1, *parent);
        graph.push_back(newSegment);
    }
}

void TrackSystem::printTrackSystem() const {
    for(const auto& i: graph) {
        for(const auto j: i) {
            std::cout << j->getTrackComponentID();

            std::cout << " -> ";
        }
        std::cout << std::endl;
    }
}


