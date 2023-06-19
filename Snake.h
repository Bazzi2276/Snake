#include <iostream>
#include "Snake_map.h"
#include "Point.h"
#include "Item.h"
#ifndef __SNAKE__
#define __SNAKE__
enum direction { WEST, NORTH, EAST, SOUTH }; 
class Snake {
public:
// private:
    int curDirection;
    int headx, heady;
    int length;
    std::deque<std::pair<int, int> > body; // (y,x)
    Snake();
    std::deque<std::pair<int, int> > getBody();
    int getLength();
    bool turnDirection(int key);
    void setSyncTime(float value);
    void movebyDoor();
    bool move(Point *p, Item* item);
};

#endif
