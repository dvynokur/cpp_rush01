//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

Display::Display(void) {
	_empty = 0;
	return ;
}

Display::Display(Parser_CPU_RAM_Time_Net *pars) {
	_empty = 0;
	_pars = pars;
	return ;
}

Display::~Display(void) {
	return ;
}

Display::Display(Display const & src) {
	*this = src;
	return ;
}

Display		&Display::operator=(Display const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void			Display::switch_mode(void)
{
	return ;
}

void			Display::set_empty(int n) {
	this->_empty = n;
	return ;
}

int				Display::get_empty(void) const {
	return (this->_empty);
}




WINDOW*		wnd;

int 		Display::init()
{
	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();

	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	wbkgd(wnd, COLOR_PAIR(1));
	wattron(wnd, A_BOLD);
	box(wnd, 0,0);
	wattroff(wnd, A_BOLD);
	
	return (0);
}

void		Display::close(void)
{
	endwin();
	exit(1);
}

void		Display::run()
{
	bool	exit_requested = false;
	int		in_char;

	Parser_CPU_RAM_Time_Net *pars = new Parser_CPU_RAM_Time_Net;

	DisplayHostUserName		d_hu(pars);
	DisplayOSInfo			d_os(pars);
	DisplayDateTime			d_dt(pars);
	DisplayCPU				d_cpu(pars);
	DisplayRAM				d_ram(pars);
	DisplayNetwork			d_net(pars);

	while(1)
	{
		in_char = wgetch(wnd);
		switch(in_char)
		{
			case 27:
				exit_requested = true;
				break ;
			case '1':
				if (d_hu.get_empty() == 0)
					d_hu.set_empty(1);
				else
					d_hu.set_empty(0);
				d_hu.display_empty(wnd);
				break ;
			case '2':
				if (d_os.get_empty() == 0)
					d_os.set_empty(1);
				else
					d_os.set_empty(0);
				break ;
			case '3':
				if (d_dt.get_empty() == 0)
					d_dt.set_empty(1);
				else
					d_dt.set_empty(0);
				break;
			case '4':
				if (d_cpu.get_empty() == 0)
					d_cpu.set_empty(1);
				else
					d_cpu.set_empty(0);
				break;
			case '5':
				if (d_ram.get_empty() == 0)
					d_ram.set_empty(1);
				else
					d_ram.set_empty(0);
				break;
			case '6':
				if (d_net.get_empty() == 0)
					d_net.set_empty(1);
				else
					d_net.set_empty(0);
				break;
			default:
				break;
		}
		clear();
		pars->get_info();
		d_hu.switch_mode(wnd);
		d_os.switch_mode(wnd);
		d_dt.switch_mode(wnd);
		d_cpu.switch_mode(wnd);
		d_ram.switch_mode(wnd);
		d_net.switch_mode(wnd);
		refresh();
		if (exit_requested)
			break;
		usleep(200000);
	}
}

void		display_info(void)
{
	return ;
}
void		display_empty(void)
{
	return ;
}

