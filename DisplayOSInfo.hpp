//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYOSINFO_HPP
# define DISPLAYOSINFO_HPP

# include "ft_gkrellm.hpp"

class DisplayOSInfo : public IMonitorDisplay
{
public:
	DisplayOSInfo();
	~DisplayOSInfo();
	DisplayOSInfo(DisplayOSInfo const & src);
	DisplayOSInfo	&operator=(DisplayOSInfo const & src);
	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);

	void			set_empty(int n);
	int				get_empty(void) const;
private:
	int				_empty;
};

#endif
