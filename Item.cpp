#include "Item.h"
using namespace std;



void Item::addTotalItem() {
    total_item++;
}

void Item::minusTotalItem() {
    total_item--;
}

Item::Item() {
    total_item = 0;
}

void Item::produceItem() {
    if (total_item < 3) {
        int  newItem =0;
        if (rand() % 3 == 0){   //rand()%3 은 0,1,2 중 하나임
            newItem = 8;
        }else{
            newItem = (rand() % 2) + 5;
        }

        clock_t now = clock();

        int y = rand() % MAP_SIZE;
        int x = rand() % MAP_SIZE;
        if (map[y][x] == 0) {
            map[y][x] = newItem;
            total_item++;

            for (int i = 0; i < 3; i++) {
                if (iv[i].y == -1) {
                    iv[i].y = y;
                    iv[i].x = x;
                    iv[i].time = now;
                    break;
                }
            }
        }
    }
}


void Item::removeItem(int y, int x) {
    if (total_item > 0) {
        for (int i = 0; i < 3; i++) {
            if (iv[i].y == y && iv[i].x == x) {
                iv[i].y = -1;
                total_item--;
            }
        }
    }
}

void Item::removeItem() {
    if (total_item > 0) {
        clock_t now = clock();
        for (int i = 0; i < 3; i++) {
            if ((float(now - iv[i].time) / CLOCKS_PER_SEC > 5) && (iv[i].y > 0)) {
                map[iv[i].y][iv[i].x] = 0;
                iv[i].y = -1;
                total_item--;
            }
        }
    }
}
