//isAllClear.c
#include <string.h>
#include <stdio.h>
#include "xxx.h"
#include <stdlib.h>
#include <ncurses.h>

void isAllClear(board *b){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(b->grid[i][j] != b->Agrid[i][j]){
                b->allClear = 0;
                return;
            }
        }
    }
    b->allClear = 1;

    if(b->allClear == 1){
        endwin();  // ncurses を終了
        printf("ナンプレクリア！おめでとう！\n");
        exit(0);
    }
}