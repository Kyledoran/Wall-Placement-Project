#include <iomanip>
#include <iostream>
#include <fstream>
#include "readInput.h"


void readInput::readFile(std::ifstream &fin) {
    if(!fin.is_open()) throw std::runtime_error("Could not open file");
    int x = 0;
    int numOfPaintings = 0;
    fin >> x;
    wallLength = x;

    fin >> x;
    wallHeight = x;

    fin >> x;
    numOfPaintings = x;
    for (int i = 0; i < numOfPaintings; ++i) {
        painting obj;
        fin >> x;
       obj.setId(x);
       fin >> x;
       obj.setPrice(x);
       fin >> x;
       obj.setLength(x);
       fin >> x;
       obj.setWidth(x);
       obj.setArea();
        paintingList.push_back(obj);
    }

}


int readInput::getWallLength() {
    return wallLength;
}

int readInput::getWallHeight() {
    return wallHeight;
}
