//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYRAM_HPP
# define DISPLAYRAM_HPP

#include "ft_gkrellm.hpp"

class DisplayRAM :public IMonitorDisplay
{
public:
	DisplayRAM(Parser_CPU_RAM_Time_Net *pars);
	~DisplayRAM();
	DisplayRAM(DisplayRAM const &src);
	DisplayRAM		&operator=(DisplayRAM const & src);

	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);

	void			set_empty(int n);
	int				get_empty(void) const;

private:
	DisplayRAM();
	int						_empty;
	Parser_CPU_RAM_Time_Net	*_pars;

};

#endif
