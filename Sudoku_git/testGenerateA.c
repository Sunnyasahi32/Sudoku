#include <stdio.h>

#include "testCommon.h"
#include "testXxx.h"
#include "xxx.h"

void testGenerateA() {
    testStart("GenerateA");

    Answer A1 = {
        "649785132\n"
        "352614879\n"
        "178329546\n"
        "831967254\n"
        "764253981\n"
        "925841367\n"
        "293576418\n"
        "516498723\n"
        "487132695\n"};

    board b = createBoard();  // 盤面を初期化
    GenerateA(&b, &A1);       // `A1` の問題データを `b.grid` にコピー

    // **1. 各マスが正しくセットされているか確認**
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char expected =
                A1.A[i * (SIZE + 1) + j];    // 改行を含むため `SIZE+1`
            if (expected == '\n') continue;  // 改行はスキップ
            assertEqualsInt(b.grid[i][j], expected);
        }
    }

    testErrorCheck();  // テスト結果を出力
}
