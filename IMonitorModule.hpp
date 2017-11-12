//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "ft_gkrellm.hpp"
//# include "Parser_CPU_RAM_Time_Net.hpp"

class Parser_CPU_RAM_Time_Net;

class IMonitorModule
{
public:
	virtual void	get_info(Parser_CPU_RAM_Time_Net const &info) = 0;

};

#endif
