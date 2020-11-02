#include<iostream>
#include<ncurses.h>
#include "snake.h"

//@author 20191622 양진우
int main(void){
    Snake snake;
    snake.init();
    snake.play();


    getch();
    endwin();
    return 0;
}
