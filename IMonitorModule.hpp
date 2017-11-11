//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include "ft_gkrellm.hpp"

class IMonitorModule
{
public:
	virtual void	get_info(void) = 0;

};

#endif
