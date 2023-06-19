#include <iostream>
#include "Item.h"
#include "Snake.h"
using namespace std;
extern float SYNC_TIME;
Snake::Snake() {
    curDirection = WEST;
    body.push_back({ MAP_SIZE / 2, MAP_SIZE / 2 + 1 });
    body.push_back({ MAP_SIZE / 2, MAP_SIZE / 2 });
    body.push_back({ MAP_SIZE / 2, MAP_SIZE / 2 - 1 });
    length = 3;
    heady = MAP_SIZE / 2;
    headx = MAP_SIZE / 2 - 1;
}
deque<pair<int, int>> Snake::getBody() {
    return body;
}
int Snake::getLength() {
    return length;
}
bool Snake::turnDirection(int key) {
    if (abs(key - curDirection) == 2) return false;
    curDirection = key;
    return true;
}
void Snake::setSyncTime(float value) {
    SYNC_TIME = value;
}


bool Snake::move(Point* p, Item* item) {
    int pop_fronty = body.front().first;
    int pop_frontx = body.front().second;

    map[pop_fronty][pop_frontx] = 0;
    map[heady][headx] = 4;

    if (curDirection == 0) headx -= 1;
    else if (curDirection == 1) heady -= 1;
    else if (curDirection == 2) headx += 1;
    else heady += 1;

    if (map[heady][headx] == 5) {
        p->addGrowItem();
        p->addCurrentLength();
        item->removeItem(heady, headx);
        map[pop_fronty][pop_frontx] = 4;
    }
    else if (map[heady][headx] == 6) {
        p->addPoisonItem();
        p->minusCurrentLength();
        item->removeItem(heady, headx);

        body.pop_front();
        int body_lasty = body.front().first;
        int body_lastx = body.front().second;
        body.pop_front();
        map[body_lasty][body_lastx] = 0;
        length--;
    }

    else if (map[heady][headx] == 8){
        //point의 growitem 증가
        p->addGrowItem();
        p->addCurrentLength();
        item->removeItem(heady, headx);
        map[pop_fronty][pop_frontx] = 4;
        length++;
        int imp=rand() % 3 ;
        if(imp == 0) {
            setSyncTime(0.17);
        }
        else if(imp ==1){
            setSyncTime(0.2);
        }
        else{
            setSyncTime(0.3);
        }

    }
    else {
        body.pop_front();
    }

    if (map[heady][headx] == 1 || map[heady][headx] == 2 || map[heady][headx] == 4) {
        return false;
    }

    if (map[heady][headx] == 7) {
        p->addUseGate();
        movebyDoor();
    }
    map[heady][headx] = 3;
    body.push_back({ heady,headx });
    return true;
}

void Snake::movebyDoor()
{
    headx = (headx == gate[0][1]) ? gate[1][1] : gate[0][1];
    heady = (heady == gate[0][0]) ? gate[1][0] : gate[0][0];


    if (headx == 0)
        curDirection = EAST;
    if (headx == 20)
        curDirection = WEST;
    if (heady == 0)
        curDirection = SOUTH;
    if (heady == 20)
        curDirection = NORTH;

    if (curDirection == EAST && map[heady][headx + 1] == 1)
    {
        if (map[heady + 1][headx] == 1)
        {
            if (map[heady - 1][headx] == 1)
            {
                if (map[heady][headx - 1] == 1)
                {
                    // cout << "SETTING DIRECTION ERROR" << endl;
                }
                else
                {
                    curDirection = WEST;
                }
            }
            else
            {
                curDirection = NORTH;
            }
        }
        else
        {
            curDirection = SOUTH;
        }
    }
    else if (curDirection == WEST && map[heady][headx - 1] == 1)
    {
        if (map[heady - 1][headx] == 1)
        {
            if (map[heady + 1][headx] == 1)
            {
                if (map[heady][headx + 1] == 1)
                {
                    // cout << "SETTING DIRECTION ERROR" << endl;
                }
                else
                {
                    curDirection = EAST;
                }
            }
            else
            {
                curDirection = SOUTH;
            }
        }
        else
        {
            curDirection = NORTH;
        }
    }
    else if (curDirection == SOUTH && map[heady + 1][headx] == 1)
    {
        if (map[heady][headx - 1] == 1)
        {
            if (map[heady][headx + 1] == 1)
            {
                if (map[heady - 1][headx] == 1)
                {
                    // cout << "SETTING DIRECTION ERROR" << endl;
                }
                else
                {
                    curDirection = NORTH;
                }
            }
            else
            {
                curDirection = EAST;
            }
        }
        else
        {
            curDirection = WEST;
        }
    }
    else if (curDirection == NORTH && map[heady - 1][headx] == 1)
    {
        if (map[heady][headx + 1] == 1)
        {
            if (map[heady][headx - 1] == 1)
            {
                if (map[heady + 1][headx] == 1)
                {
                    // cout << "SETTING DIRECTION ERROR" << endl;
                }
                else
                {
                    curDirection = SOUTH;
                }
            }
            else
            {
                curDirection = WEST;
            }
        }
        else
        {
            curDirection = EAST;
        }
    }

    if (curDirection == EAST) {
        headx++;
    }
    else if (curDirection == WEST) {
        headx--;
    }
    else if (curDirection == SOUTH) {
        heady++;
    }
    else if (curDirection == NORTH) {
        heady--;
    }
}
