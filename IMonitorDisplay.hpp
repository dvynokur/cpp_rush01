//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "ft_gkrellm.hpp"

class IMonitorDisplay
{
public:
	virtual int		init(void) = 0;
	virtual void	run(void) = 0;
	virtual void	close(void) = 0;
};

#endif
