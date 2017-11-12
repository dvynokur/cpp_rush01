//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYDATETIME_HPP
# define DISPLAYDATETIME_HPP

# include "ft_gkrellm.hpp"

class DisplayDateTime : public IMonitorDisplay
{
public:
	DisplayDateTime();
	~DisplayDateTime();
	DisplayDateTime(DisplayDateTime const &src);
	DisplayDateTime		&operator=(DisplayDateTime const &src);

	void				display_info(WINDOW *wnd);
	void				display_empty(WINDOW *wnd);
	void				switch_mode(WINDOW *wnd);

	void				set_empty(int n);
	int					get_empty(void) const;
private:
	int					_empty;
	
};

#endif
