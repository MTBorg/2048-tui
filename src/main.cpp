#include <ncurses.h>

#include "square.h"
#include "constants.h"
#include "board.h"

int main(int argc, char *argv[]) {
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();

	Board b;
	b.draw();

	int ch;

	while((ch = getch()) != KEY_F(1)){	
		switch(ch){
			case KEY_LEFT:
				b.swipeLeft();
				break;
			case KEY_RIGHT:
				b.swipeRight();
				break;
			case KEY_UP:
				b.swipeUp();
				break;
			case KEY_DOWN:
				b.swipeDown();
				break;	
			case KEY_BACKSPACE:
				break;
		}
		b.insertRandom();
		b.draw();
	}

	endwin();
	return 0;
}
