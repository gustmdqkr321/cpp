#include<iostream>
#include<ncurses.h>
#include "snake.h"

int main(void){
    Snake snake;
    snake.init();
    snake.play();


    getch();
    endwin();
    return 0;
}
