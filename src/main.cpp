#include <iostream>
#include <fstream>
#include "readInput.h"
#include "wallPlacement.h"
#include "painting.h"
using namespace std;
int main(int argc, char **argv) {
    std::ifstream fin(argv[1]);
    std::ofstream output("test-highvalue.txt");
    std::ofstream output1("test-custom.txt");
    std::ofstream output2("test-bruteforce.txt");
    readInput test;
    wallPlacement test1;
    test.readFile(fin);
    test1.setWallLength(test.getWallLength());
    test1.setWallHeight(test.getWallHeight());
    test1.setWallArea();
    test1.expensiveFirst(test.paintingList);
    test1.printFinalList(output);
    test1.averagePrice(test.paintingList);
    test1.printFinalList(output1);
    test1.bruteForceVectors(test.paintingList,test.paintingList.size(),0);
    test1.bruteForceCalc(output2);


}
