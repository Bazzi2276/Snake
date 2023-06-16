#include <iostream>
#include "Mission.h"

Mission::Mission() {
    B = 7;
    growItem = 3;
    poisonItem = 2;
    useGate = 1;

    Bflag = false;
    growItemFlag = false;
    poisonItemFlag = false;
    useGateFlag = false;
};


int Mission::getB(){
    return B;
}
int Mission::getGrowItem(){
    return growItem;
}
int Mission::getPoisonItem(){
    return poisonItem;
}
int Mission::getUseGate(){
    return useGate;
}


void Mission::setB(int x){
    B = x;
}
void Mission::setGrowItem(int x){
    growItem = x;
}
void Mission::setPoisonItem(int x){
    poisonItem = x;
}
void Mission::setUseGate(int x){
    useGate = x;
}


void Mission::checkB(Point *p){
    if(p->getCurrentLength() >= B) Bflag= true;
}
void Mission::checkGrowItem(Point *p){
    if(p->getGrowItem() >= growItem) growItemFlag = true;
}
void Mission::checkPoisonItem(Point *p){
    if(p->getPoisonItem() >= poisonItem) poisonItemFlag = true;
}
void Mission::checkUseGate(Point *p){
    if(p->getUseGate()>= useGate) useGateFlag = true;
}

void Mission::updateAll(Point *p){
    Mission::checkB(p);
    Mission::checkGrowItem(p);
    Mission::checkPoisonItem(p);
    Mission::checkUseGate(p);
}


bool Mission::getBflag(){ return Bflag;}
bool Mission::getPoisonItemFlag(){return poisonItemFlag;}
bool Mission::getGrowItemFlag(){return growItemFlag;}
bool Mission::getUseGateFlag(){return useGateFlag;}

bool Mission::checkStageClear(){return (Bflag&&poisonItemFlag&&growItemFlag&&useGateFlag);}

