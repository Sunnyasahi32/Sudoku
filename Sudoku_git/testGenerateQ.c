#include <stdio.h>
#include "testCommon.h"
#include "testXxx.h"
#include "xxx.h"

void testGenerateQ() {
    testStart("GenerateQ");

    Question Q1 = {
        ".49....3.\n"
        ".5.61....\n"
        "..8.295.6\n"
        "8..9.7..4\n"
        "7......81\n"
        ".25.413..\n"
        "2...76.1.\n"
        "5..4.87..\n"
        ".87....95\n"
    };

    board b = createBoard();  // 盤面を初期化
    GenerateQ(&b, &Q1);       // `Q1` の問題データを `b.grid` にコピー

    // **1. 各マスが正しくセットされているか確認**
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char expected = Q1.Q[i * (SIZE + 1) + j];  // 改行を含むため `SIZE+1`
            if (expected == '\n') continue; // 改行はスキップ
            assertEqualsInt(b.grid[i][j], expected);
        }
    }

    testErrorCheck();  // テスト結果を出力
}
