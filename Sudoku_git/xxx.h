// xxx.h

#ifndef __XXX
#define __XXX
#define SIZE 9

// 盤面構造体
typedef struct {
    // 2変数は念のため0を明示
    char grid[SIZE][SIZE];   // 9×9盤面のシリアライズ文字列用の枠を作っておく
    char Qgrid[SIZE][SIZE];  // 固定値比較用
    char Agrid[SIZE][SIZE];  // 解答比較用
    int allClear;
} board;

// userinput定義
typedef struct {
    char ch;  // 入力された文字
    int x;    // x座標
    int y;    // y座標
} changeNum;

// 問題格納用構造体
typedef struct {
    const char *Q;
} Question;

// 解答格納用構造体
typedef struct {
    const char *A;
} Answer;
#define SIZE 9


// **** プロトタイプ宣言集
board createBoard();
void GenerateQ(board *b, Question *Q);
void isAllClear(board *b);
void drawboard(const char grid[SIZE][SIZE], char lightNum);
void getUserInput(changeNum *input);
void GenerateA(board *b, Answer *A);



#endif  // __XXX
