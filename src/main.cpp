#include <iostream>

#include "TrackSystem.h"
#include "TrackBuilder.h"
#include "TrackComponent.h"

int main() {
    std::string fName = "trackConfig.txt";

    // For initial track creation
    auto* tb = new TrackBuilder(fName);
    tb->buildTrack();

    // Restore terminal settings
    delete tb;

    // Create graph based on the provided file handle
    auto* ts = new TrackSystem(fName);
    bool buildSuccess = ts->buildTrackFromFile();

    // Find optimal path and simulate train motion
    auto* tc = new TrainController(ts->getGraph(), ts->getTrain());



    // For debugging
    if(buildSuccess) {
        ts->printTrackSystem();
    }
    else {
        std::cout << "Unable to process track system. Please check track config file" << std::endl;
    }

    return 0;
}
