#include "testXxx.h"
#include <stdio.h>
#include "testCommon.h"
#include "xxx.h"

void testDrawBoard(){
    int i;
    char lightNum;
    board b;
    testStart("drawBoard");
    board b = createBoard();
    initscr();
    start_color();
    for(i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            b.grid[i][j] = 1;
        }
    }
    drawBoard(b.grid, lightNum);
    printw("ハイライトされていなければ正常");
    lightNum = 1;
    drawBoard(b.grid, lightNum);
    printw("ハイライトされていれば正常");
}