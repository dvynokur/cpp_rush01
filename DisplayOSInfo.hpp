//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYOSINFO_HPP
# define DISPLAYOSINFO_HPP

# include "ft_gkrellm.hpp"


class DisplayOSInfo : public Display
{
public:
	DisplayOSInfo(Parser_CPU_RAM_Time_Net *pars);

	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);
};

#endif
