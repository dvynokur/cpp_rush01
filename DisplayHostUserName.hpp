//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYHOSTUSERNAME_HPP
# define DISPLAYHOSTUSERNAME_HPP

# include "ft_gkrellm.hpp"

class DisplayHostUserName : public IMonitorDisplay
{
public:
	DisplayHostUserName();
	~DisplayHostUserName();
	DisplayHostUserName(DisplayHostUserName const &src);
	DisplayHostUserName	&operator=(DisplayHostUserName const & src);
	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);
	int				get_empty(void) const ;
	void			set_empty(int n);

private:
	int				_empty;
};

#endif
