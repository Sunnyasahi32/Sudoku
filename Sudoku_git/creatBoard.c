//createBoard.c
#include <string.h>
#include <stdio.h>
#include "xxx.h"

board createBoard() {
    board b;
    memset(b.grid, 0, sizeof(b.grid)); // 0で初期化

    //確かめるために出力
    // for (int i = 0; i < SIZE; i++) {
    //     for (int j = 0; j < SIZE; j++) {
    //         printf("%d", board.grid[i][j]);
    //     }
    //     printf("\n");
    // }


    return b;
}