#include<iostream>
#include<ncurses.h>


int main(){
    initscr();
    noecho();
    addch('H'|A_UNDERLINE);
    addch('E'|A_UNDERLINE);
    addch('L'|A_BOLD);
    addch('L'|A_BOLD);
    addch('O'|A_BOLD);
    getch();
    endwin();
    return 0;
}