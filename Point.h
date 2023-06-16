#include <iostream>
#ifndef __POINT__
#define __POINT__

class Point {
private:
    int currentLength;
    int maxLength;
    int growItem;
    int poisonItem;
    int useGate;

    int xitem;
public:
    Point();
    int getCurrentLength();
    int getMaxLength();
    int getGrowItem();
    int getPoisonItem();
    int getUseGate();
    
    //값을 update하기 위한 함수
    void updateMaxLength();
    void addCurrentLength();
    void minusCurrentLength();
    void addMaxLength();
    void addGrowItem();
    void addPoisonItem();
    void addUseGate();
};

#endif