// getUserInput.c

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "testCommon.h"
#include "testXxx.h"
#include "xxx.h"

void getUserInput(changeNum *input) {
    input->x = 0;
    input->y = 0;
    printw("Enter a number [ch x y]: ");
    flushinp();  // 入力バッファのクリア
    refresh();   // 画面更新

    scanw(" %c %d %d", &input->ch, &input->x, &input->y);

    input->x = input->x - 1;
    input->y = input->y - 1;

    // 'q' が入力された場合、ゲーム終了
    if (input->ch == 'q') {
        endwin();  // ncurses を終了
        exit(0);
    }
}
