//
// Created by Kyle Doran on 8/28/21.
//

#ifndef INC_21F_PA01_PAINTING_H
#define INC_21F_PA01_PAINTING_H


class painting {
private:
    int price;
    int id;
    int length;
    int width;
    int topLeftX;
    int topLeftY;
    int bottomRightX;
    int bottomRightY;
    int area;
    bool placed;
public:
    painting();
    void setPlaced(bool x);
    bool getPlaced();
    void setArea();
    int getArea();
    void setPrice(int x);
    int getPrice();
    void setId(int x);
    int getId();
    void setLength(int x);
    int getLength();
    void setWidth(int x);
    int getWidth();
    void setTopLeftX(int x);
    int getTopLeftX();
    void setTopLeftY(int x);
    int getTopLeftY();
    void setBottomRightX(int x);
    int getBottomRightX();
    void setBottomRightY(int x);
    int getBottomRightY();



};


#endif //INC_21F_PA01_PAINTING_H
