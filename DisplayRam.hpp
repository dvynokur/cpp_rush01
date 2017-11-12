//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYRAM_HPP
# define DISPLAYRAM_HPP

#include "ft_gkrellm.hpp"

class DisplayRAM :public Display
{
public:
	DisplayRAM(Parser_CPU_RAM_Time_Net *pars);
	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);
};

#endif
