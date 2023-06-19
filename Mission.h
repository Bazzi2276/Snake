#include <iostream>
#include "Point.h"

class Mission {
private:
    bool Bflag;
    bool growItemFlag;
    bool poisonItemFlag;
    bool useGateFlag;
    int B;
    int growItem;
    int poisonItem;
    int useGate;
public:
    Mission();
    int getB();
    int getGrowItem();
    int getPoisonItem();
    int getUseGate();


    void checkB(Point *p);
    void checkGrowItem(Point *p);
    void checkPoisonItem(Point *p);
    void checkUseGate(Point *p);
    void updateAll(Point *p);
    void setB(int b);
    void setGrowItem(int x);
    void setPoisonItem(int x);
    void setUseGate(int x);



    bool getBflag();
    bool getGrowItemFlag();
    bool getPoisonItemFlag();
    bool getUseGateFlag();


    bool checkStageClear();
};
