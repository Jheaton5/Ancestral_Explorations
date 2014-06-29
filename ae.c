#include <ncurses.h>
#include <string.h>
#include <stdio.h>

void title_page(void)
{	
char mesg[]= "A N C E S T R A L   E X P L O R A T I O N S";
int row,col;					/* to store the number of rows and cols */
	getmaxyx(stdscr,row,col);	/* get the number of rows and columns */
	mvprintw((row/2)-2,(col-strlen(mesg))/2,"%s",mesg);  /* print the message at the center of the screen */
	refresh();					/* Print it on to the real screen */
	getch();					/* Wait for user input */
	clear();
}	
void print_menu()
{	
		/* Set up the menu */
	mvprintw(3,25,"1. Modify the Person Data.       ");
	mvprintw(5,25,"2. Modify the Marriage Data.     ");
	mvprintw(7,25,"4. Browse the Data in the Files. ");
	mvprintw(9,25,"5. Print the Lists.              ");
	mvprintw(11,25,"6. Print a Family Group Sheet.   ");
	mvprintw(13,25,"6. Print a Pedigree Chart.       ");
	mvprintw(15,25,"7. Exit the Program.             ");
	mvprintw(18,25,"Enter the Number of Your Choice... ");
	refresh();					/* Print it on to the real screen */
	getch();
	clear();

}

int main()
{	
	initscr();					/* Start curses mode 		  */
	curs_set(0);
	title_page();
	print_menu();
	endwin();

	return 0;
}

