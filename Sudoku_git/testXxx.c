// testXxx.c
#include "testXxx.h"

#include <stdio.h>

#include "testCommon.h"
#include "xxx.h"

int main() {
    printf("##### Test start #####\n");
    testcreateBoard();
    testGenerateQ();
    //testGenerateA();

    // 最終エラー統計処理
    testErrorCheck();  // この行は絶対に消さない
    printf("##### Test finish #####\n");
    return 0;
}
