//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYDATETIME_HPP
# define DISPLAYDATETIME_HPP

# include "ft_gkrellm.hpp"


class DisplayDateTime : public Display
{
public:
	DisplayDateTime(Parser_CPU_RAM_Time_Net *pars);

	void				display_info(WINDOW *wnd);
	void				display_empty(WINDOW *wnd);
	void				switch_mode(WINDOW *wnd);
};

#endif
