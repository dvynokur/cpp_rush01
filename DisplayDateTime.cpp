//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"


DisplayDateTime::DisplayDateTime(void) {
	_empty = 0;
	return ;
}

DisplayDateTime::~DisplayDateTime(void) {
	return ;
}

DisplayDateTime::DisplayDateTime(DisplayDateTime const &src)
{
	*this = src;
	return ;
}

DisplayDateTime		&DisplayDateTime::operator=(DisplayDateTime const &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void				DisplayDateTime::display_info(WINDOW *wnd)
{
	DateTimeModule	dt;
	int				x;
	int				y;
	int				line = 11;

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
	mvwprintw(wnd, line, 30, "%d", dt.getHour());
	mvwprintw(wnd, line, 33, ": %d", dt.getMinutes());
	mvwprintw(wnd, line, 38, ": %d", dt.getSeconds());
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

void				DisplayDateTime::set_empty(int n) {
	this->_empty = n;
	return ;
}

int					DisplayDateTime::get_empty(void) const {
	return (this->_empty);
}