//
// Created by Kyle Doran on 8/28/21.
//

#ifndef INC_21F_PA01_READINPUT_H
#define INC_21F_PA01_READINPUT_H
#include <vector>
#include "painting.h"


class readInput{
private:
    int wallLength;
    int wallHeight;

public:
 void readFile(std::ifstream &fin);
    std::vector<painting> paintingList;
    int getWallLength();
    int getWallHeight();
};





#endif //INC_21F_PA01_READINPUT_H
