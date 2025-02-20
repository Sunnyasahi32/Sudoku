#include <string.h>
#include <stdio.h>
#include "xxx.h"

#include "xxx.h"

void GenerateA(board *b, Answer *A) {
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            while (A->A[index] == '\n') index++; // 改行をスキップ
            b->Agrid[i][j] = A->A[index++];
        }
    }
}
