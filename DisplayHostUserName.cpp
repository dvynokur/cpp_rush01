//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

DisplayHostUserName::DisplayHostUserName(void) {
	_empty = 0;
	return ;
}

DisplayHostUserName::DisplayHostUserName(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
	return ;
}


DisplayHostUserName::~DisplayHostUserName(void) {
	return ;
}

DisplayHostUserName::DisplayHostUserName(DisplayHostUserName const &src)
{
	*this = src;
	return ;
}

DisplayHostUserName	&DisplayHostUserName::operator=(DisplayHostUserName const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void			DisplayHostUserName::display_info(WINDOW *wnd)
{
	HostUserName	hu;

	int x;
	int y;
	int line = 1;

	hu.get_info(*this->_pars);
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, line, i, "="); }
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "1.\tUsername: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", hu.getUserName().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tHostname: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", hu.getHostName().c_str());
	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 4, i, "="); }

	return ;
}

void			DisplayHostUserName::display_empty(WINDOW *wnd)
{
	int x;
	int y;
	getmaxyx(wnd, y, x);
	// clear();
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 1, i, "="); }


	attron(A_BOLD);
	mvwprintw(wnd, 2, 2, "1.\tTo enable Hostname/Username module press \"1\"");


	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 4, i, "="); }
	attrset(A_NORMAL);
	return ;
}

void			DisplayHostUserName::switch_mode(WINDOW *wnd)
{
	if (this->_empty == 0)
		this->display_info(wnd);
	else
		this->display_empty(wnd);
}

void			DisplayHostUserName::set_empty(int n) {
	this->_empty = n;
	return ;
}

int				DisplayHostUserName::get_empty(void) const {
	return (this->_empty);
}
