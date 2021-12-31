#include <vector>
#include <fstream>
#include "wallPlacement.h"

void wallPlacement::setWallLength(int x) {
    wallLength = x;
}
int wallPlacement::getWallLength() {
    return wallLength;
}
void wallPlacement::setWallHeight(int x) {
    wallHeight = x;
}
int wallPlacement::getWallHeight() {
    return wallHeight;
}
void wallPlacement::setWallArea() {
    wallArea = wallLength * wallHeight;
}
int wallPlacement::getWallArea() {
    return wallArea;
}

void wallPlacement::placePainting(std::vector<painting> paintingList) {
    finalPaintings.push_back(paintingList[0]);
    paintingList[0].setPlaced(true);
    finalPaintings[0].setTopLeftX(0);
    finalPaintings[0].setTopLeftY(0);
    finalPaintings[0].setBottomRightX(finalPaintings[0].getLength() -1);
    finalPaintings[0].setBottomRightY(finalPaintings[0].getWidth()-1);
    areaUsed = finalPaintings[0].getArea();
    int i = 1;
    while ((areaUsed < wallArea) && (i < paintingList.size())){
        if(finalPaintings[i-1].getBottomRightX()+paintingList[i].getLength() < 1023 && !paintingList[i].getPlaced()){
            paintingList[i].setPlaced(true);
            finalPaintings.push_back(paintingList[i]);
            finalPaintings[i].setTopLeftX(finalPaintings[i-1].getBottomRightX()+1);
            finalPaintings[i].setTopLeftY(finalPaintings[i-1].getTopLeftY());
            finalPaintings[i].setBottomRightX(finalPaintings[i].getTopLeftX()+finalPaintings[i].getLength()-1);
            finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
            areaUsed = areaUsed + finalPaintings[i].getArea();
        }
        else {

            for ( int k = i; k < paintingList.size(); ++k) {
                if(finalPaintings[i-1].getBottomRightX()+paintingList[k].getLength() < 1023 && !paintingList[k].getPlaced()){
                    paintingList[k].setPlaced(true);
                    finalPaintings.push_back(paintingList[k]);
                    finalPaintings[i].setTopLeftX(finalPaintings[i-1].getBottomRightX()+1);
                    finalPaintings[i].setTopLeftY(finalPaintings[i-1].getTopLeftY());
                    finalPaintings[i].setBottomRightX(finalPaintings[i].getTopLeftX()+finalPaintings[i].getLength()-1);
                    finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
                    areaUsed = areaUsed + finalPaintings[i].getArea();
                    k = paintingList.size();
                    i++;
                }

            }

            int maxY = 0;
            for (int j = 0; j < finalPaintings.size(); ++j) {
                if(maxY < finalPaintings[j].getBottomRightY())
                    maxY = finalPaintings[j].getBottomRightY();
            }
            if(maxY+paintingList[i].getWidth()+1 < 768 && !paintingList[i].getPlaced()){
                paintingList[i].setPlaced(true);
                finalPaintings.push_back(paintingList[i]);
                finalPaintings[i].setTopLeftX(0);
                finalPaintings[i].setTopLeftY(maxY+1);
                finalPaintings[i].setBottomRightX(finalPaintings[i].getLength()-1);
                finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
                areaUsed = areaUsed + finalPaintings[i].getArea();

            }
            else{
                int check = 0;
                for ( int k = i; k < paintingList.size(); ++k) {
                    if(maxY+paintingList[k].getWidth()+1 < 768 && !paintingList[k].getPlaced()){
                        paintingList[k].setPlaced(true);
                        finalPaintings.push_back(paintingList[k]);
                        finalPaintings[i].setTopLeftX(0);
                        finalPaintings[i].setTopLeftY(maxY+1);
                        finalPaintings[i].setBottomRightX(finalPaintings[i].getLength()-1);
                        finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
                        areaUsed = areaUsed + finalPaintings[i].getArea();
                        k = paintingList.size();
                        check++;
                    }


                }
                if(check == 0)
                    break;

            }


            //case where painting is to long to place to the right of previous painting (find max y value place one below at x=0 maybe?
            //check if height will be too great for wall similar to if statement above
            //could also iterate thru painting list here to find a painting that will fit to the right of previous painting if there isnt one then do the method above
        }

        i++;
    }

}

void wallPlacement::printFinalList(std::ofstream &out) {
    if(!out.is_open()) throw std::runtime_error("Could not open file");
    int sum = 0;

    for (int i = 0; i < finalPaintings.size(); ++i) {
        sum +=finalPaintings[i].getPrice();
    }
    out << sum << std::endl;
    for (int j = 0; j <finalPaintings.size() ; ++j) {
        out << finalPaintings[j].getId() << " " << finalPaintings[j].getPrice() << " " << finalPaintings[j].getLength() << " " << finalPaintings[j].getWidth() << " " << finalPaintings[j].getTopLeftX() << " " << finalPaintings[j].getTopLeftY() << std::endl;
    }

    finalPaintings.clear();
}

void wallPlacement::expensiveFirst(std::vector<painting> paintingList) {
    for (int i = 0; i < paintingList.size(); i++) {
        for (int j = i; j < (paintingList.size()); j++) {
            if (paintingList[i].getPrice() < paintingList[j].getPrice()) {
                std::swap(paintingList[i], paintingList[j]);
            }
        }
    }
    placePainting(paintingList);

}

void wallPlacement::averagePrice(std::vector<painting> paintingList) {
    int averagePrice = 0;
    std::vector<painting> newList;

    for (int j = 0; j < paintingList.size(); ++j) {
        averagePrice+=paintingList[j].getPrice();

    }
    averagePrice = averagePrice / paintingList.size();
    for (int k = 0; k < paintingList.size(); ++k) {
        if (paintingList[k].getPrice() >= averagePrice)
            newList.push_back(paintingList[k]);
    }

    for (int i = 0; i < newList.size(); i++) {
        for (int j = i; j < (newList.size()); j++) {
            if (newList[i].getArea() > newList[j].getArea()) {
                std::swap(newList[i], newList[j]);
            }
        }
    }
    for (int l = 0; l < paintingList.size(); ++l) {
        if (paintingList[l].getPrice() < averagePrice)
            newList.push_back(paintingList[l]);
    }
    //std::cout << averagePrice << std::endl;
    //for (int k = 0; k < paintingList.size(); ++k) {
    //std::cout << paintingList[k].getArea() << "  " << paintingList[k].getPrice() << std::endl;
    //}

    placePainting(newList);

}


void wallPlacement::bruteForceVectors(std::vector<painting> paintingList, int n, int i) {
    if(n >= 10){
        std::cout << "data set exceeds max size" << std::endl;
    }
    else {
        int j;
        if (i == n) {
            vector<painting> temp;
            for (j = 0; j < n; j++) {
                temp.push_back(paintingList[j]);
            }
            if (temp.size() > 0) {
                paintingVectors.push_back(temp);
                temp.clear();
            }
        }
        else

            for (j = i; j < n; j++) {


                std::swap(paintingList[i], paintingList[j]);
                bruteForceVectors(paintingList, n, i + 1);


                bruteForceVectors(paintingList, i, j);
            }
    }
}

wallPlacement::wallPlacement() {
    wallHeight = 0;
    wallLength = 0;
    wallArea = 0;
    areaUsed = 0;

}

void wallPlacement::bruteForcePlace(vector<painting> paintingList) {
    finalPaintings.push_back(paintingList[0]);
    paintingList[0].setPlaced(true);
    finalPaintings[0].setTopLeftX(0);
    finalPaintings[0].setTopLeftY(0);
    finalPaintings[0].setBottomRightX(finalPaintings[0].getLength() -1);
    finalPaintings[0].setBottomRightY(finalPaintings[0].getWidth()-1);
    areaUsed = finalPaintings[0].getArea();
    int i = 1;
    while ((areaUsed < wallArea) && (i < paintingList.size())){
        if(finalPaintings[i-1].getBottomRightX()+paintingList[i].getLength() < 1023 && !paintingList[i].getPlaced()){
            finalPaintings.push_back(paintingList[i]);
            paintingList[i].setPlaced(true);
            finalPaintings[i].setTopLeftX(finalPaintings[i-1].getBottomRightX()+1);
            finalPaintings[i].setTopLeftY(finalPaintings[i-1].getTopLeftY());
            finalPaintings[i].setBottomRightX(finalPaintings[i].getTopLeftX()+finalPaintings[i].getLength()-1);
            finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
            areaUsed = areaUsed + finalPaintings[i].getArea();
        }
        else {

            for ( int k = i; k < paintingList.size(); ++k) {
                if(finalPaintings[i-1].getBottomRightX()+paintingList[k].getLength() < 1023 && !paintingList[i].getPlaced()){
                    finalPaintings.push_back(paintingList[k]);
                    paintingList[k].setPlaced(true);
                    finalPaintings[i].setTopLeftX(finalPaintings[i-1].getBottomRightX()+1);
                    finalPaintings[i].setTopLeftY(finalPaintings[i-1].getTopLeftY());
                    finalPaintings[i].setBottomRightX(finalPaintings[i].getTopLeftX()+finalPaintings[i].getLength()-1);
                    finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
                    areaUsed = areaUsed + finalPaintings[i].getArea();
                    k = paintingList.size();
                    i++;
                }

            }

            int maxY = 0;
            for (int j = 0; j < finalPaintings.size(); ++j) {
                if(maxY < finalPaintings[j].getBottomRightY())
                    maxY = finalPaintings[j].getBottomRightY();
            }
            if(maxY+paintingList[i].getWidth()+1 < 768 && !paintingList[i].getPlaced()){
                finalPaintings.push_back(paintingList[i]);
                paintingList[i].setPlaced(true);
                finalPaintings[i].setTopLeftX(0);
                finalPaintings[i].setTopLeftY(maxY+1);
                finalPaintings[i].setBottomRightX(finalPaintings[i].getLength()-1);
                finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
                areaUsed = areaUsed + finalPaintings[i].getArea();

            }
            else{
                int check = 0;
                for ( int k = i; k < paintingList.size(); ++k) {
                    if(maxY+paintingList[k].getWidth()+1 < 768 && !paintingList[k].getPlaced()){
                        paintingList[k].setPlaced(true);
                        finalPaintings.push_back(paintingList[k]);
                        finalPaintings[i].setTopLeftX(0);
                        finalPaintings[i].setTopLeftY(maxY+1);
                        finalPaintings[i].setBottomRightX(finalPaintings[i].getLength()-1);
                        finalPaintings[i].setBottomRightY(finalPaintings[i].getTopLeftY()+finalPaintings[i].getWidth()-1);
                        areaUsed = areaUsed + finalPaintings[i].getArea();
                        k = paintingList.size();
                        check++;
                    }


                }
                if(check == 0){
                    bruteForceFinalPaintings.push_back(finalPaintings);
                    break;
                }


            }

            //case where painting is to long to place to the right of previous painting (find max y value place one below at x=0 maybe?
            //check if height will be too great for wall similar to if statement above
            //could also iterate thru painting list here to find a painting that will fit to the right of previous painting if there isnt one then do the method above
        }

        i++;
    }
    bruteForceFinalPaintings.push_back(finalPaintings);
}

void wallPlacement::bruteForceCalc(std::ofstream& out) {
    if(paintingVectors.empty()){
        out << "dataset exceeds max size" << std::endl;
    }
    else {
        for (int l = 0; l < paintingVectors.size(); ++l) {
            bruteForcePlace(paintingVectors[l]);
            finalPaintings.clear();
        }
//need to reset vectors before each call in loop
        int maxValueIndex = 0;
        int maxValue = 0;

        for (int i = 0; i < bruteForceFinalPaintings.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < bruteForceFinalPaintings[i].size(); ++j) {
                sum += bruteForceFinalPaintings[i][j].getPrice();
            }
            if (sum > maxValue) {
                maxValue = sum;
                maxValueIndex = i;
            }
        }
        out << maxValue << std::endl;
        for (int k = 0; k < bruteForceFinalPaintings[maxValueIndex].size(); ++k) {
            out << bruteForceFinalPaintings[maxValueIndex][k].getId() << " "
                << bruteForceFinalPaintings[maxValueIndex][k].getPrice() << " "
                << bruteForceFinalPaintings[maxValueIndex][k].getLength() << " "
                << bruteForceFinalPaintings[maxValueIndex][k].getWidth() << " "
                << bruteForceFinalPaintings[maxValueIndex][k].getTopLeftX() << " "
                << bruteForceFinalPaintings[maxValueIndex][k].getTopLeftY() << std::endl;
        }
    }
}

