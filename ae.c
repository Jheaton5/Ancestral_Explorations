#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

void title_page(void)
{	
char mesg[]= "A N C E S T R A L   E X P L O R A T I O N S";
int row,col;													/* to store the number of rows and cols */
	getmaxyx(stdscr,row,col);									/* get the number of rows and columns */
	mvprintw((row/2)-2,(col-strlen(mesg))/2,"%s",mesg);  		/* print the message at the center of the screen */
	refresh();													/* Print it on to the real screen */
	getch();													/* Wait for user input */
	clear();
}	
void print_menu()
{	char *choices[] = { 										/* array that contains the menu items */
            "Modify the Person Data.       ",
			"Modify the Marriage Data.     ",
			"Browse the Data in the Files. ",
			"Print the Lists.              ",
			"Print a Family Group Sheet.   ",
			"Print a Pedigree Chart.       ",
			"Exit the Program.             ",
            };

	ITEM **my_items;											/* pointer to a pointer to the menu items */
	int c;				
	MENU *my_menu;												/* pointer to the menu block */
	int n_choices, i;
	initscr();													/* set ncurses mode */
	cbreak();													/* makes it unnecessary to hit enter on keyboard input */
	noecho();													/* charactes typed do not appear on screen */
	keypad(stdscr, TRUE);										/* enables the keypad of the user's terminal */
	
	n_choices = ARRAY_SIZE(choices);							/* returns the number of elements in choices */
	set_menu_format(NULL,n_choices,1);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *)); 	/* allocate memory for the size of the whole menu */

	for(i = 0; i < n_choices; ++i)								/* loop through the menu items */
	        my_items[i] = new_item(choices[i], NULL); 	/* set up the menu items with new_item() */
	my_items[n_choices] = (ITEM *)NULL;							/* set the last item to NULL */

	my_menu = new_menu((ITEM **)my_items);						/* create the menu */
	mvprintw(LINES - 2, 0, "F2 to Exit");						/* print the Exit command */
	post_menu(my_menu);											/* post the menu to the hidden screen */
	refresh();													/* make the hidden screen active */

	while((c = getch()) != KEY_F(2))							/* loop through the menu choices */
	{   switch(c)
	    {	case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);			/* move down one line */
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);				/* move up one line */
				break;
		}
	}	

	free_item(my_items[0]);										/* clear the menu items and return */
	free_item(my_items[1]);
	free_item(my_items[2]);
	free_item(my_items[3]);
	free_item(my_items[4]);
	free_item(my_items[5]);
	free_item(my_items[6]);
	free_menu(my_menu);
	endwin();

}

int main()														/* Maint Program */
{	
	initscr();													/* Start curses mode */
	curs_set(0);
	title_page();												/* Print the Title Page */
	print_menu();												/* Print the Menu */
	endwin();

	return 0;													/* Program terminates */
}

