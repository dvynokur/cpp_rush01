//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"
#include "OS_Info.hpp"
// #include <intrin.h>
#include <sys/resource.h>


#include <sys/types.h>
#include <sys/sysctl.h>

WINDOW*		wnd;


int 	init()
{
	// srand(time(0));
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

void		close(void)
{
	endwin();
	exit(1);
}

void	basic_window(void)
{
	// pid_t		pid;
	// if (pid = fork)
	// 	process...
}

void	run()
{
	int		tick;
	bool	exit_requested = false;
	int		in_char;

	DisplayHostUserName		d_hu;
	DisplayOSInfo			d_os;
	DisplayDateTime			d_dt;

	// d_os.display_empty(wnd);

	// d_hu.switch_mode(wnd);

	// clear();
	while(1)
	{
		clear();

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
			default:
				break;
		}
		d_hu.switch_mode(wnd);
		d_os.switch_mode(wnd);
		d_dt.switch_mode(wnd);
		// clear();
		refresh();
		if (exit_requested)
			break;
		usleep(40000);
	}

	// int n_char = wgetch(wnd);
	// while(n_char != '\n')
	// {
	// 	n_char = wgetch(wnd);
	// 	if (n_char == 27)
	// 		close();
	// }
}



int			main(void)
{
	int		init_status = init();
	if (init_status == 0)
		run();

	close();


	// FILE * in;
	// char buff[256];

	// if(!(in = popen("top -l 1 -n 0 -s 0", "r"))){
	// 	return 1;
	// }
	// while(fgets(buff, sizeof(buff), in)!=NULL){
	// 	std::cout << buff;
	// }
	// pclose(in);

	// OS_Info osInfo;

    return (0);
}
