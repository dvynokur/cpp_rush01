//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

DisplayCPU::DisplayCPU(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
	return ;
}

void			DisplayCPU::display_info(WINDOW *wnd)
{
	CPUModule	cpu;

	int x;
	int y;
	int line = 15;

	cpu.get_info(*this->_pars);
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++)
		mvwprintw(wnd, 15, i, "=");
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "4.\tProcesses: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", cpu.getProcesses().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tCPU usage: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", cpu.getCPU_usage().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tProcessor Model: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%s", cpu.getModelCPU().c_str());
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvwprintw(wnd, ++line, 2, "\tNumber of Cores: ");
	attron(COLOR_PAIR(4));
	mvwprintw(wnd, line, 30, "%d", cpu.getNumCPU());
	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 20, i, "="); }

	return ;
}

void			DisplayCPU::display_empty(WINDOW *wnd)
{
	int x;
	int y;
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));
	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 15, i, "="); }


	attron(A_BOLD);
	mvwprintw(wnd, 17, 2, "4.\tTo enable CPU module press \"4\"");


	attrset(A_NORMAL);
	attron(COLOR_PAIR(2));

	for (int i = 2; i < x - 2; i++) { mvwprintw(wnd, 20, i, "="); }
	attrset(A_NORMAL);
	return ;
}

void			DisplayCPU::switch_mode(WINDOW *wnd)
{
	if (this->_empty == 0)
		this->display_info(wnd);
	else
		this->display_empty(wnd);
}
