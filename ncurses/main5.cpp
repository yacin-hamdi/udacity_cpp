#include<unistd.h>
#include<ncurses.h>

WINDOW *create_newwin(int height, int width, int y_start, int x_start);

int main(){
    WINDOW *win1, *win2;
    int height = 10;
    int width = 10;

    initscr();
    noecho();
    win1 = create_newwin(height, width, 0, 0);
    win2 = create_newwin(height, width, 9, 9);
    box(win1, '+', '+');
    box(win2, '+', '+');
    wrefresh(win1);
    wrefresh(win2);

    getch();
    endwin();
    delwin(win1);
    delwin(win2);
    return 0;
}

WINDOW *create_newwin(int height, int width, int y_start, int x_start){
    WINDOW* local_win = newwin(height, width, y_start, x_start);
    refresh();
    return local_win;
}