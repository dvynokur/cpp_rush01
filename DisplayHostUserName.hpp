//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYHOSTUSERNAME_HPP
# define DISPLAYHOSTUSERNAME_HPP

# include "ft_gkrellm.hpp"
# include "IMonitorDisplay.hpp"


class DisplayHostUserName : public Display
{
public:
	DisplayHostUserName(Parser_CPU_RAM_Time_Net *pars);
	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);
};

#endif
