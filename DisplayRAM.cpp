//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

DisplayRAM::DisplayRAM(void) {
	_empty = 0;
	return ;
}

DisplayRAM::DisplayRAM(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
	return ;
}

DisplayRAM::~DisplayRAM(void) {
	return ;
}

DisplayRAM::DisplayRAM(DisplayRAM const & src) {
	*this = src;
	return ;
}

DisplayRAM		&DisplayRAM::operator=(DisplayRAM const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void			DisplayRAM::display_info(WINDOW *wnd)
{
	RAM_Module	ram;

	int x;
	int y;
	int line = 21;

	ram.get_info(*this->_pars);
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++)
		mvwprintw(wnd, 21, i, "=");
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "5.\tRAM: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", ram.getRAM().c_str());
	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 23, i, "="); }

	return ;
}

void			DisplayRAM::display_empty(WINDOW *wnd)
{
	int x;
	int y;
	getmaxyx(wnd, y, x);
	// clear();
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 21, i, "="); }


	attron(A_BOLD);
	mvwprintw(wnd, 22, 2, "5.\tTo enable RAM module press \"5\"");


	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 23, i, "="); }
	attrset(A_NORMAL);
	return ;
}

void			DisplayRAM::switch_mode(WINDOW *wnd)
{
	if (this->_empty == 0)
		this->display_info(wnd);
	else
		this->display_empty(wnd);
}

void			DisplayRAM::set_empty(int n) {
	this->_empty = n;
	return ;
}

int				DisplayRAM::get_empty(void) const {
	return (this->_empty);
}
