// xxx.c

// main
/*実行方法
    数独を始める：make
    関数のテスト：make test
*/


//WindowsでもMacでもcuesesを使用できるので消さない
#ifdef __CYGWIN__
#include <ncurses.h>
#elif _WIN64
#include "PDCurses-3.9/curses.h"
#elif _WIN32
#include "C/curses.h"
#elif _WIN64
#include "curses.h"
#elif _WIN32
#include "curses.h"
#else
#include <ncurses.h>
#endif
#include <string.h>

#include "xxx.h"

Question q1 = {
    ".49785132\n"
    "352614879\n"
    "178329546\n"
    "831967254\n"
    "764253981\n"
    "925841367\n"
    "293576418\n"
    "516498723\n"
    "487132695\n"
    };
  
  Answer a1 = {
    "649785132\n"
    "352614879\n"
    "178329546\n"
    "831967254\n"
    "764253981\n"
    "925841367\n"
    "293576418\n"
    "516498723\n"
    "487132695\n"
  };

int lightNum;

int main() {
    initscr();            // ncursesの初期化
    start_color();        // カラー機能の有効化
    changeNum input;
    board b = createBoard();
    GenerateQ(&b, &q1);
    GenerateA(&b, &a1);

    while(1){
        drawboard(b.grid, lightNum);
        isAllClear(&b);
        getUserInput(&input);

        if(input.x == -1 && input.y == -1){
            lightNum = input.ch; //色をつける
        }
        else if((input.x >-1 && input.x<9 )&& (input.x >-1 && input.x<9)){
           
            
            if('.' != b.Qgrid[input.x][input.y]){ //固定値判定   
             }
            else{
               b.grid[input.x][input.y] = input.ch;
            }
        }

    }
    endwin();   // ncursesの終了
}
