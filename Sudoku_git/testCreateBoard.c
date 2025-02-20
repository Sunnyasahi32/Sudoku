//testCreateBoard.c
#include "testXxx.h"
#include <stdio.h>
#include "testCommon.h"
#include "xxx.h"

void testcreateBoard() {
    int i;
    board b, ans; 
    testStart("createBoard");
    b = createBoard(); 
    for(i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            ans.grid[i][j] = 0;
        }
    }
    assertEqualsIntArray(&b, &ans, SIZE*SIZE); //boardとansが等しいか確認
}