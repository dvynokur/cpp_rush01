//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYNETWORK_HPP
# define DISPLAYNETWORK_HPP

#include "ft_gkrellm.hpp"

class DisplayNetwork :public IMonitorDisplay
{
public:
	DisplayNetwork(Parser_CPU_RAM_Time_Net *pars);
	~DisplayNetwork();
	DisplayNetwork(DisplayNetwork const &src);
	DisplayNetwork		&operator=(DisplayNetwork const & src);

	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);

	void			set_empty(int n);
	int				get_empty(void) const;

private:
	DisplayNetwork();
	int						_empty;
	Parser_CPU_RAM_Time_Net	*_pars;

};

#endif
