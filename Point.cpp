#include <iostream>
#include "Point.h"

Point::Point(){
    currentLength = 3;
    maxLength = 3;
    growItem = 0;
    poisonItem = 0;
    useGate = 0;
}

int Point::getCurrentLength(){
    return currentLength;
}
int Point::getMaxLength(){
    return maxLength;
}
int Point::getGrowItem(){
    return growItem;
}
int Point::getPoisonItem(){
    return poisonItem;
}
int Point::getUseGate(){
    return useGate;
}

void Point::updateMaxLength(){
    if(currentLength>maxLength) maxLength = currentLength;
}

void Point::addCurrentLength(){
    currentLength++;
}
void Point::minusCurrentLength(){
    currentLength--;
}
void Point::addMaxLength(){
    maxLength++;
}
void Point::addGrowItem(){
    growItem++;
}
void Point::addPoisonItem(){
    poisonItem++;
}
void Point::addUseGate(){
    useGate++;
}