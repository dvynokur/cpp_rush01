//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "ft_gkrellm.hpp"
# include "IMonitorDisplay.hpp"

class Display : public IMonitorDisplay
{
public:
	Display(Parser_CPU_RAM_Time_Net *pars);
	Display(void);
	~Display();
	Display(Display const & src);
	Display	&operator=(Display const & src);

	void	display_info(void);
	void	display_empty(void);
	
	void			switch_mode(void);
	void			set_empty(int n);
	int				get_empty(void) const;

	virtual int				init(void);
	virtual void			run(void);
	virtual void			close(void);

protected:
	int						_empty;
	Parser_CPU_RAM_Time_Net	*_pars;

};

#endif
