
#include "Snake.h"
#include "Snake_map.h"
#include "Display.h"
#include "Item.h"
#include "keyboardEventhandler.h"
float SYNC_TIME = 0.3;

using namespace std;


int main() {
    WINDOW* snake_win, * point_win, * mission_win, * notice_win;
    Snake sk = Snake();
    Point* p = new Point();
    Mission* m = new Mission();
    Item* item = new Item();
    srand(time(NULL));
    setlocale(LC_ALL, "");
    map_init(stage);
    initscr();
    resize_term(60, 100);
    colorSetting();
    border('*', '*', '*', '*', '*', '*', '*', '*');
    mvprintw(1, 1, "SNAKE GAME");
    refresh();
    snake_win = newwin(30, 60, 3, 3);
    wbkgd(snake_win, COLOR_PAIR(1));
    wattron(snake_win, COLOR_PAIR(8));
    mvwprintw(snake_win, 1, 1, "Snake_game window");
    mvwprintw(snake_win, 2, 1, "STAGE : %d", stage);
    wborder(snake_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(snake_win);


    point_win = newwin(15, 29, 3, 64);
    wbkgd(point_win, COLOR_PAIR(1));
    wattron(point_win, COLOR_PAIR(8));
    mvwprintw(point_win, 1, 1, "Score_board");
    wborder(point_win, '|', '|', '-', '-', '+', '+', '+', '+');
    updatePoint(point_win, p);
    wrefresh(point_win);


    mission_win = newwin(15, 29, 18, 64);
    wbkgd(mission_win, COLOR_PAIR(1));
    wattron(mission_win, COLOR_PAIR(8));
    mvwprintw(mission_win, 1, 1, "Mission");
    wborder(mission_win, '|', '|', '-', '-', '+', '+', '+', '+');
    updateMission(mission_win, m, p);



    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    clock_t startClock;
    clock_t endClock;
    startClock = clock();

    int cnt = 0;
    while (1) {
        if (!keyEventHandler(sk)) {
            displayDead(notice_win);
            break;
        }

        endClock = clock();
        if ((float)(endClock - startClock) / CLOCKS_PER_SEC >= SYNC_TIME) {
            //Snake is dead
            if (!sk.move(p, item) || sk.getLength() < 3) {
                displayDead(notice_win);
                break;
            }

            item->removeItem();
            item->produceItem();

            startClock = endClock;
            updatePoint(point_win, p);
            updateMission(mission_win, m, p);
            if((p->getMaxLength()>forGate) && waitGate){
                makeGate();
                waitGate = false;
            }

            if ( p->getMaxLength() > forRandomWall && waitRandomWall)
            {
                makeRandomWall();
                waitRandomWall = false;
            }
            if (m->checkStageClear() && stage == 4) {
                displayGameClear(notice_win);
                break;
            }//next Stage
            else if (m->checkStageClear()) {
                displayNext(notice_win);
                stage++;
                wattron(snake_win, COLOR_PAIR(8));
                mvwprintw(snake_win, 2, 1, "STAGE : %d", stage);

                sk = Snake();
                delete p;
                delete m;
                delete item;
                p = new Point();
                m = new Mission();
                item = new Item();
                waitGate = true;
                waitRandomWall = true;

                map_init(stage);
                cin.ignore(2, '\n');
            }

            //snake window 동기화
            draw_snakewindow(snake_win);
        }
    }
    getch();
    delwin(snake_win);
    delwin(point_win);
    delwin(mission_win);
    endwin();

    delete p;
    delete m;
    delete item;

    return 0;
}
