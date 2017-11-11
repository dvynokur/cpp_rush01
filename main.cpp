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
	HostUserName	hu;
	DateTimeModule	dt;

	int x;
	int y;
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));

	mvwprintw(wnd, 1, 2, "==================================================");
	// attrset(A_NORMAL);

	mvwprintw(wnd, 2, 2, "username: %s", hu.getUserName().c_str());
	// mvwprintw(wnd, 3, 2, "hostname: %s", hu.getHostName().c_str());

	int n_char = wgetch(wnd);
	while(n_char != '\n')
	{
		n_char = wgetch(wnd);
		if (n_char == 27)
			close();
	}
}



int			main(void)
{
	// HostUserName	hu;
	// CPUModule		cm;

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
