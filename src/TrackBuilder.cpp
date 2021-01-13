//
// Created by Raphael Lopez on 2021-01-12.
//

#include "../inc/TrackBuilder.h"

TrackBuilder::TrackBuilder() :
    currRow(0), currCol(0), exitFlag(false), saveConfirmation(false) {

    // Configure ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Print welcome string
    char welcomeMsg[] = "Enter track below";
    printMessage(currRow, currCol, welcomeMsg);

    // Move cursor to next line
    currRow++;

    // Initialize first line
    trackConfig.emplace_back("");
}

TrackBuilder::~TrackBuilder() {
    // Restore terminal settings
    endwin();
}

/*---------------- Accessors ----------------*/

bool TrackBuilder::getExitFlag() const {
    return exitFlag;
}


/*------------------ Input -----------------*/

bool TrackBuilder::isValidInput(char input) {
    bool isValid = false;

    for(int i = 0; i < strlen(validInputs); i++) {
        if(input == validInputs[i]) {
            isValid = true;
        }
    }

    // Newline ('\') without junction ('=') is considered invalid
    if(input == NEWLANE && junctionTracker.empty()) {
        isValid = false;
    }

    return isValid;
}

void TrackBuilder::processInput(char input) {
    if(isValidInput(input)) {

        // CONFIRM: End track configuration
        if(input == ENTER && !saveConfirmation) {
            char confirmMsg[] = "Press enter to confirm track configuration";
            printMessage(currRow + 2, 0, confirmMsg);
            saveConfirmation = true;
        }

        // End track configuration
        else if(input == ENTER) {
            exitFlag = true;
            trackFile.open("./../trackConfig.txt");

            for(auto & i : trackConfig) {
                trackFile << i << '\n';
            }

            trackFile.close();
        }

        // Handle junctions
        else if(input == NEWLANE) {
            // Insert new line
            trackConfig.emplace_back("");
            currRow++;

            // Choose column based on last junction inserted
            currCol = junctionTracker.top();
            junctionTracker.pop();
        }

        else {
            // Save validated character
            trackConfig[currRow - 1] += input;

            // Track junctions for next line
            if (input == JUNCTION) {
                junctionTracker.push(currCol);
            }

            // Display validated character
            mvaddch(currRow, currCol, input);
            mvaddch(currRow, currCol+1, ' ');
            currCol += 2;
            wrefresh(stdscr);
        }
    }
}


/*------------------ Output ------------------*/

void TrackBuilder::printMessage(int row, int col, char *msg) {
    for(int i = 0; i < strlen(msg); i++) {
        mvaddch(row, col, msg[i]);
        col++;
    }
}


/*------------------ Control -----------------*/

void TrackBuilder::buildTrack() {
    char input;
    while(!this->getExitFlag()) {
        input = getch();
        this->processInput(input);
    }
}
