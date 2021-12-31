//
// Created by Kyle Doran on 9/1/21.
//

#ifndef INC_21F_PA01_WALLPLACEMENT_H
#define INC_21F_PA01_WALLPLACEMENT_H

#include "painting.h"
#include <vector>
#include "iostream"
using namespace std;

class wallPlacement {
private:
    int wallLength;
    int wallArea;
    int wallHeight;
    int areaUsed;
public:
   wallPlacement();
   void setWallLength(int x);
   int getWallLength();
   void setWallArea();
   int getWallArea();
   void setWallHeight(int x);
   int getWallHeight();
   void printFinalList(std::ofstream &out);
    std::vector<painting> finalPaintings;
    vector<vector<painting> > paintingVectors;
    vector<vector<painting> > bruteForceFinalPaintings;
    void placePainting(std::vector<painting>paintingList);
    void expensiveFirst(std::vector<painting>paintingList);
    void expensiveFirstPlace(std::vector<painting> paintingList);
    void averagePrice(std::vector<painting>paintingList);
    void bruteForceVectors(std::vector<painting> paintingList, int n, int i);
    void bruteForcePlace(vector<painting> paintingList);
    void bruteForceCalc(std::ofstream& out);
};


#endif //INC_21F_PA01_WALLPLACEMENT_H
