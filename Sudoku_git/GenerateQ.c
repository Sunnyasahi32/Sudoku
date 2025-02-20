//generateQ.c
#include <string.h>
#include <stdio.h>
#include "xxx.h"

void GenerateQ(board *b, Question *Q){
    b->allClear = 0;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
          b->grid[i][j] = Q->Q[i * (SIZE + 1) + j];
          b->Qgrid[i][j] = Q->Q[i * (SIZE + 1) + j];
          //printf("%c", b.grid[i][j]);
      }
    //printf("\n");
  }
  }