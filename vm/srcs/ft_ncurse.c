#include <vm.h>
#include <time.h>

/*
 * http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
 */

int		wait_plz(int ms)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 < (unsigned long)ms * CLOCKS_PER_SEC);
	return (1);
}

void		init_ncurse(void)
{
	static int	first = 0;

	if (!first)
	{
		initscr();
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		init_pair(2, COLOR_BLACK, COLOR_WHITE);
		init_pair(3, COLOR_RED, COLOR_WHITE);
//		system("afplay ~/Downloads/Pokemon.mp3 &");
		first = 1;
	}
}

void		ft_visu(t_info *info)
{
	t_proc			*act;
	int				i;
	static int		wait = 1;
	WINDOW *board;
//	WINDOW *player;

	i = 0;
	init_ncurse();
	board = subwin(stdscr, LINES, COLS * 2 / 3, 0, 0);
	//player = subwin(stdscr, LINES, COLS / 3, 0, COLS / 3);
	box(board, ACS_VLINE, ACS_HLINE);
    //box(player, ACS_VLINE, ACS_HLINE);
	while (i < MEM_SIZE)
	{
		attron(COLOR_PAIR(1));
		act = info->first_processus;
		while (act)
		{
			if (act->pc == i)
			{
				if (act->carry)
					attron(COLOR_PAIR(3));
				else
					attron(COLOR_PAIR(2));
				break;
			}
			act = act->next;
		}
		wprintw(board, "%.2x ", info->board[i]);
		i++;
	}
	refresh();
	wait_plz(wait);
	/*i = wgetch();
	if (i == KEY_LEFT)
		wait = 1000;*/
//	system("pkill afplay; afplay ~/Downloads/final_victory.mp3 &");
//	endwin();
}
