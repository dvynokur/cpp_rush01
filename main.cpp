//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"
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

void	run()
{
	HostUserName	hu;
	DateTimeModule	dt;


	int x;
	int y;
	getmaxyx(wnd, y, x);
	attron(COLOR_PAIR(2));

	mvwprintw(wnd, 1, 2, "==================================================");
	attrset(A_NORMAL);

	mvwprintw(wnd, 2, 2, "username: %s", hu.getUserName().c_str());
	mvwprintw(wnd, 3, 2, "hostname: %s", hu.getHostName().c_str());

	int n_char = wgetch(wnd);
	while(n_char != '\n'){
		n_char = wgetch(wnd);
		if (n_char == 27)
			close();
	}
}


// double get_wall_time()
// {
//     struct timeval time;
//     if (gettimeofday(&time,NULL)){
//         //  Handle error
//         return 0;
//     }
//     return (double)time.tv_sec + (double)time.tv_usec * .000001;
// }

double get_cpu_time()
{
   	return (double)clock() / CLOCKS_PER_SEC;
}

int64_t		get_physical_memory(void)
{
	int mib[2];
    int64_t physical_memory;
    size_t length;

    // Get the Physical memory size
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    length = sizeof(int64_t);
    sysctl(mib, 2, &physical_memory, &length, NULL, 0);
    return (physical_memory);

}

int			main(void)
{
	HostUserName hu;

	std::cout << hu.getUserName() << std::endl;
	// int		init_status = init();
	// if (init_status == 0)
	// 	run();

	// close();

	std::cout << get_cpu_time() << std::endl;



	// std::cout << get_physical_memory() << std::endl;

	struct rusage r_usage;

	if (getrusage(RUSAGE_SELF, &r_usage)) {
	    /* ... error handling ... */
	}

	printf("Total User CPU = %ld.%ld\n",
	        r_usage.ru_utime.tv_sec,
	        r_usage.ru_utime.tv_usec);
	printf("Total System CPU = %ld.%ld\n",
	        r_usage.ru_stime.tv_sec,
	        r_usage.ru_stime.tv_usec);





	return (0);
}
