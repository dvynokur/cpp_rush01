//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

DisplayNetwork::DisplayNetwork(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
	return ;
}

void			DisplayNetwork::display_info(WINDOW *wnd)
{
	NetworkModule	nt;

	int x;
	int y;
	int line = 24;

	nt.get_info(*this->_pars);
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++)
		mvwprintw(wnd, 24, i, "=");
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "6.\tNetworks: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", nt.getNetworks().c_str());
	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 26, i, "="); }

	return ;
}

void			DisplayNetwork::display_empty(WINDOW *wnd)
{
	int x;
	int y;
	getmaxyx(wnd, y, x);
	// clear();
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 24, i, "="); }


	attron(A_BOLD);
	mvwprintw(wnd, 25, 2, "6.\tTo enable Network module press \"6\"");


	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 26, i, "="); }
	attrset(A_NORMAL);
	return ;
}

void			DisplayNetwork::switch_mode(WINDOW *wnd)
{
	if (this->_empty == 0)
		this->display_info(wnd);
	else
		this->display_empty(wnd);
}
