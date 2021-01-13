//
// Created by Raphael Lopez on 2021-01-11.
//

#ifndef TRAINSIMULATION_TRACK_H
#define TRAINSIMULATION_TRACK_H


class Track {
    public:
        Track();

    private:
        Track* prev;
        Track* next;

};


#endif //TRAINSIMULATION_TRACK_H
