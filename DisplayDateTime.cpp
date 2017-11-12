//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

DisplayDateTime::DisplayDateTime(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
}

void				DisplayDateTime::display_info(WINDOW *wnd)
{
	DateTimeModule	dt;
	int				x;
	int				y;
	int				line = 11;

	dt.get_info(*this->_pars);
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++)
		mvwprintw(wnd, 11, i, "=");

	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "3.\tDate: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%d", dt.getDay());
	mvwprintw(wnd, line, 33, ": %d", dt.getMonth());
	mvwprintw(wnd, line, 38, ": %d", dt.getYear());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tTime: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", dt.getTime().c_str());
	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 14, i, "="); }

	return ;
}

void				DisplayDateTime::display_empty(WINDOW *wnd)
{
	int x;
	int y;
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 11, i, "="); }

	attron(A_BOLD);
	mvwprintw(wnd, 12, 2, "3.\tTo enable Date/Time module press \"3\"");


	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 14, i, "="); }
	attrset(A_NORMAL);

	return ;
}

void				DisplayDateTime::switch_mode(WINDOW *wnd)
{
	if (this->_empty == 0)
		this->display_info(wnd);
	else
		this->display_empty(wnd);
}
