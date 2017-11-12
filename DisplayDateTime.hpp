//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYDATETIME_HPP
# define DISPLAYDATETIME_HPP

# include "ft_gkrellm.hpp"
# include "IMonitorDisplay.hpp"


class DisplayDateTime : public IMonitorDisplay
{
public:
	DisplayDateTime(Parser_CPU_RAM_Time_Net *pars);
	~DisplayDateTime();
	DisplayDateTime(DisplayDateTime const &src);
	DisplayDateTime		&operator=(DisplayDateTime const &src);

	void				display_info(WINDOW *wnd);
	void				display_empty(WINDOW *wnd);
	void				switch_mode(WINDOW *wnd);

	void				set_empty(int n);
	int					get_empty(void) const;
private:
	DisplayDateTime();
	int						_empty;
	Parser_CPU_RAM_Time_Net	*_pars;
};

#endif
