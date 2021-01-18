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

#define TRACK           '-'
#define JUNCTION        '='
#define TRAIN           'T'
#define SIGNAL_GREEN    'o'
#define SIGNAL_RED      'x'
#define DIR_WEST        'W'
#define DIR_EAST        'E'
#define SPACING         ' '
#define NEWLANE         '\\'
#define ENTER           '\n'

const char validInputs[] = {TRACK, JUNCTION, TRAIN, SIGNAL_GREEN, SIGNAL_RED, SPACING, NEWLANE, \
                            DIR_WEST, DIR_EAST, ENTER};

class TrackBuilder {
private:
    // Display functionality
    int currRow, currCol;
    std::stack<int> junctionTracker;

    //  File functionality
    std::string fileName;
    bool saveConfirmation, exitFlag;
    std::vector<std::string> trackConfig;
    std::ofstream trackFile;

public:
    explicit TrackBuilder(std::string fName);
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
