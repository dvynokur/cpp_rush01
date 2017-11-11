//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "ft_gkrellm.hpp"

class CPUModule : public IMonitorModule
{
public:
	CPUModule();
	~CPUModule();
	CPUModule(CPUModule const &src);
	CPUModule	&operator=(CPUModule const &src);
	void			get_info(void);

	// setters:



	// getters:



private:
	int				_numCPU;

};

#endif
