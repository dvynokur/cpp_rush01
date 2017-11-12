//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "ft_gkrellm.hpp"

class IMonitorDisplay
{
public:
	virtual void	display_info(WINDOW *wnd) = 0;
	virtual void	display_empty(WINDOW *wnd) = 0;
	virtual void	switch_mode(WINDOW *wnd) = 0;
};

#endif
