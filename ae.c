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
int row,col;					/* to store the number of rows and cols */
	getmaxyx(stdscr,row,col);	/* get the number of rows and columns */
	mvprintw((row/2)-2,(col-strlen(mesg))/2,"%s",mesg);  /* print the message at the center of the screen */
	refresh();					/* Print it on to the real screen */
	getch();					/* Wait for user input */
	clear();
}	
void print_menu()
{	char *choices[] = {
            "Modify the Person Data.       ",
			"Modify the Marriage Data.     ",
			"Browse the Data in the Files. ",
			"Print the Lists.              ",
			"Print a Family Group Sheet.   ",
			"Print a Pedigree Chart.       ",
			"Exit the Program.             ",
           
                  };

	ITEM **my_items;
	int c;				
	MENU *my_menu;
	int n_choices, i;
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
	        my_items[i] = new_item(choices[i], choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "F2 to Exit");
	post_menu(my_menu);
	refresh();

	while((c = getch()) != KEY_F(2))
	{   switch(c)
	    {	case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
		}
	}	

	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
	endwin();

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

