#include <iostream>
#ifndef __POINT__
#define __POINT__
class Point {
private:
    int poisonItem;
    int useGate;
    int currentLength;
    int maxLength;
    int growItem;
    int xitem;
public:
    Point();
    int getPoisonItem();
    int getUseGate();
    int getCurrentLength();
    int getMaxLength();
    int getGrowItem();
    void updateMaxLength();
    void addCurrentLength();
    void minusCurrentLength();
    void addMaxLength();
    void addGrowItem();
    void addPoisonItem();
    void addUseGate();
};

#endif
