//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAYCPU_HPP
# define DISPLAYCPU_HPP

# include "ft_gkrellm.hpp"

class DisplayCPU : public IMonitorDisplay
{
public:
	DisplayCPU(Parser_CPU_RAM_Time_Net *pars);
	~DisplayCPU();
	DisplayCPU(DisplayCPU const & src);
	DisplayCPU		&operator=(DisplayCPU const & src);

	void			display_info(WINDOW *wnd);
	void			display_empty(WINDOW *wnd);
	void			switch_mode(WINDOW *wnd);

	void			set_empty(int n);
	int				get_empty(void) const;

private:
	DisplayCPU();
	int						_empty;
	Parser_CPU_RAM_Time_Net	*_pars;
	
};

#endif
