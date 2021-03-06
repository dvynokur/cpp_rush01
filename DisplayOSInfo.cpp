//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

DisplayOSInfo::DisplayOSInfo(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
	return ;
}

void			DisplayOSInfo::display_info(WINDOW *wnd)
{
	OS_Info		os;

	os.get_info(*this->_pars);
	int x;
	int y;
	int line = 6;
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 5, i, "="); }
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, line, 2, "2.\tProduct name: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", os.getProductName().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tProduct version: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", os.getProductVersion().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tBuild version: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", os.getbuildVersion().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tProduct copyright: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", os.getproductCopyright().c_str());
	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 10, i, "="); }

	return ;
}

void			DisplayOSInfo::display_empty(WINDOW *wnd)
{
	int x;
	int y;
	getmaxyx(wnd, y, x);
	// clear();
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 5, i, "="); }

	attron(A_BOLD);
	mvwprintw(wnd, 7, 2, "2.\tTo enable OS Info module press \"2\"");


	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 10, i, "="); }
	attrset(A_NORMAL);
	return ;
}

void			DisplayOSInfo::switch_mode(WINDOW *wnd)
{
	if (_empty == 0)
		display_info(wnd);
	else if (_empty == 1)
		display_empty(wnd);
}
