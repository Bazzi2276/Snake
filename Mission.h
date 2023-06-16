#include <iostream>
#include "Point.h"

class Mission {
private:
    int B;
    int growItem;
    int poisonItem;
    int useGate;
    bool Bflag;
    bool growItemFlag;
    bool poisonItemFlag;
    bool useGateFlag;
public:
    Mission();
    int getB();
    int getGrowItem();
    int getPoisonItem();
    int getUseGate();

    //Mission 값 설정 
    void setB(int b);
    void setGrowItem(int x);
    void setPoisonItem(int x);
    void setUseGate(int x);

    //현재 Point와 비교해서 Mission 달성 여부 확인
    void checkB(Point *p);
    void checkGrowItem(Point *p);
    void checkPoisonItem(Point *p);
    void checkUseGate(Point *p);
    void updateAll(Point *p);

    //각각의 목표를 clear했는지 
    bool getBflag();
    bool getGrowItemFlag();
    bool getPoisonItemFlag();
    bool getUseGateFlag();

    //모든 목표를 clear했는지
    bool checkStageClear();
};