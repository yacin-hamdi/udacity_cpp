#include<unistd.h>
#include<ncurses.h>

WINDOW *create_newwin(int height, int width, int y_start, int x_start);

int main(){
    int height = 10;
    int width = 100;
    WINDOW* win1, *win2;
    
    initscr();
    noecho();
    win1 = create_newwin(height, width, 0, 0);
    box(win1, 0, 0);
    mvwprintw(win1, 1, 2, "hello");
    mvwprintw(win1, 1, 8, "from win1");
    wrefresh(win1);

    sleep(2);

    win2 = create_newwin(height, width, 11, 0);  
    box(win2, 0, 0);
    mvwprintw(win2, 1, 2, "hello");
    mvwprintw(win2, 1, 8, "from win2");
    
    wrefresh(win2);
    getch();
    endwin();
    return 0;



}

WINDOW *create_newwin(int height, int width, int y_start, int x_start){
    WINDOW *LOCAL_WIN = newwin(height, width, y_start, x_start);
    refresh();
    return LOCAL_WIN;
}