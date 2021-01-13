//
// Created by Raphael Lopez on 2021-01-12.
//

#ifndef TRAINSIMULATION_TRACKBUILDER_H
#define TRAINSIMULATION_TRACKBUILDER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#include <curses.h>

#define TRACK     '-'
#define JUNCTION  '='
#define SIGNAL    'o'
#define NEWLANE   '\\' // Used to move to next junction
#define ENTER     '\n'

const char validInputs[] = {TRACK, JUNCTION, SIGNAL, NEWLANE, ENTER};

class TrackBuilder {
private:
    // Display functionality
    int currRow, currCol;
    std::stack<int> junctionTracker;

    //  File functionality
    bool saveConfirmation{}, exitFlag;
    std::vector<std::string> trackConfig;
    std::ofstream trackFile;

public:
    TrackBuilder();
    ~TrackBuilder();

    /*-------- Accessors --------*/
    bool getExitFlag() const;

    /*---------- Input ----------*/
    bool isValidInput(char input);
    void processInput(char input);

    /*---------- Output ---------*/
    static void printMessage(int row, int col, char* msg);

    /*--------- Control ---------*/
    void buildTrack();

};


#endif //TRAINSIMULATION_TRACKBUILDER_H
