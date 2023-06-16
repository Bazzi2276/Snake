#include <iostream>
#include "Snake_map.h"

int stage = 0;
bool waitGate = 1;
int forGate = 5;
bool waitRandomWall = 1;
int gate[2][GATE_SIZE] = { { 0, 0 }, { 0, 0 } };
int map[MAP_SIZE][MAP_SIZE];

void map_init(int stage) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < MAP_SIZE; i++) {
        map[i][MAP_SIZE - 1] = WALL;
        map[i][0] = WALL;
        map[MAP_SIZE - 1][i] = WALL;
        map[0][i] = WALL;
    }

    map[MAP_SIZE / 2][MAP_SIZE / 2] = SNAKE_BODY;
    map[MAP_SIZE / 2][MAP_SIZE / 2 + 1] = SNAKE_BODY;
    map[MAP_SIZE / 2][MAP_SIZE / 2 - 1] = SNAKE_BODY;


    //stage별로 wall 다르게
    if (stage == 1) {
        for (int i = 0; i < 10; i++) {
            map[i][8] = 2;
        }
    }
    else if (stage == 2) {
        for (int i = 5; i < 14; i++) {
            map[5][i] = 2;
        }

        for (int i = 5; i < 14; i++) {
            map[i][5] = 2;
        }
    }
    else if (stage == 3) {
        for (int i = 2; i < 15; i++) {
            map[i][i] = 2;
        }
    }
    else if (stage == 4) {
        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                if (i % 2 == 1 && j % 2 == 1)
                {
                    map[i][j] = 2;
                }
            }
        }
    }

    //immune wall 적용
    findImmuneWall();
}

//wall과 gate가 등장하면 안되는 ImmuneWall 구분
void findImmuneWall() {
    int dy[4] = { 0,1,0,-1 };
    int dx[4] = { 1,0,-1,0 };

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == 2) {

                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny < 0 || ny >= MAP_SIZE || nx < 0 || nx >= MAP_SIZE) continue;
                    if (map[ny][nx] != 1 && map[ny][nx] != 2) cnt++;
                }

                //사방이 wall인 immune wall
                if (cnt == 0) map[i][j] = 1;
            }
        }
    }
}


// wall중에서 Gate 생성
void makeGate() {
    int x1, y1, x2, y2;

    do
    {
        x1 = rand() % MAP_SIZE;
        y1 = rand() % MAP_SIZE;
    } while (map[y1][x1] != 2);

    map[y1][x1] = GATE;

    do
    {
        x2 = rand() % MAP_SIZE;
        y2 = rand() % MAP_SIZE;
    } while (map[y2][x2] != 2);

    map[y2][x2] = GATE;

    gate[0][0] = y1;
    gate[0][1] = x1;
    gate[1][0] = y2;
    gate[1][1] = x2;
}

// Snake의 길이가 maxLenth의 절반만큼 도달 시 랜덤으로 몇몇 바닥이 벽으로 변함.
void makeRandomWall()
{
    for (size_t i = 0; i < 8; i++)
    {
        int x1, y1;

        do
        {
            x1 = rand() % MAP_SIZE;
            y1 = rand() % MAP_SIZE;
        } while (map[y1][x1] == 0);

        map[y1][x1] = WALL;
    }
    
}
