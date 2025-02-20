// drawboard.c

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "testCommon.h"
#include "testXxx.h"
#include "xxx.h"

void drawboard(const char grid[SIZE][SIZE], char lightNum) {
    clear();  // 画面のクリア

    // カラーペアの定義（ブロックごとの背景色変更）
    init_pair(1, COLOR_BLACK, COLOR_WHITE);  // 通常マス (黒文字, 白背景)
    init_pair(2, COLOR_WHITE, COLOR_BLACK);  // 通常マス (白文字, 黒背景)
    init_pair(3, COLOR_WHITE, COLOR_RED);    // lightNum 背景 (赤背景, 白文字)
    init_pair(4, COLOR_BLACK, COLOR_RED);    // lightNum 背景 (赤背景, 黒文字)

    printw("    1  2  3   4  5  6   7  8  9\n");
    printw("  -------------------------------\n");

    for (int y = 0; y < SIZE; y++) {
        printw("%d |", y + 1);  // 行番号を表示

        for (int x = 0; x < SIZE; x++) {
            char ch = grid[y][x];  // 盤面の数字or空白を取得
            int color_pair;

            // 3x3ブロックごとに異なる背景色を設定
            if ((y / 3 + x / 3) % 2 == 0) {
                color_pair = (ch == lightNum) ? 3 : 1;
            } else {
                color_pair = (ch == lightNum) ? 4 : 2;
            }

            attron(COLOR_PAIR(color_pair));  // 色の設定
            printw(" %c ", ch);              // 文字の表示

            attroff(COLOR_PAIR(color_pair));  // 色の解除

            // 3マスごとに縦の区切り線
            if (x % 3 == 2) {
                printw("|");
            }
        }
        printw("\n");

        // 3行ごとに横の区切り線
        if (y % 3 == 2) {
            printw("  -------------------------------\n");
        }
    }

    refresh();  // 画面の更新
}