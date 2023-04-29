#include<ncurses.h>


int main(){

    initscr();
    addch('H');
    addch('E');
    addch('L');
    addch('L');
    addch('O');
    addch('!');
    getch();
    endwin();
    return 0;
}