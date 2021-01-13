#include <iostream>

#include "../inc/Track.h"
#include "../inc/TrackBuilder.h"

int main() {
    // For initial track creation
    auto* tb = new TrackBuilder();
    tb->buildTrack();

    // Restore terminal settings
    delete tb;




    return 0;
}
