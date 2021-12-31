//
// Created by Kyle Doran on 8/28/21.
//

#include "painting.h"

void painting::setPrice(int x) {
   price = x;
}

int painting::getPrice() {
    return price;
}

void painting::setId(int x) {
    id = x;
}

int painting::getId() {
    return id;
}

void painting::setLength(int x) {
    length = x;
}

int painting::getLength() {
    return length;
}

void painting::setWidth(int x) {
    width = x;
}

int painting::getWidth() {
    return width;
}

void painting::setTopLeftX(int x) {
    topLeftX = x;

}

int painting::getTopLeftX() {
    return topLeftX;
}

void painting::setTopLeftY(int x) {
    topLeftY = x;
}

int painting::getTopLeftY() {
    return topLeftY;
}

void painting::setBottomRightX(int x) {
    bottomRightX = x;
}

int painting::getBottomRightX() {
    return bottomRightX;
}

void painting::setBottomRightY(int x) {
    bottomRightY = x;

}

int painting::getBottomRightY() {
    return bottomRightY;
}

void painting::setArea() {
        area = length * width;
}

int painting::getArea() {
    return area;
}

bool painting::getPlaced() {
    return placed;
}

void painting::setPlaced(bool x) {
    placed = x;
}

painting::painting() {
    price = 0;
     id= 0;
    length=0;
     width=0;
     topLeftX=0;
     topLeftY=0;
    bottomRightX=0;
     bottomRightY=0;
     area=0;
     placed=false;

}
