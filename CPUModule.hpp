//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "ft_gkrellm.hpp"
# include <cstdlib>
# include <exception>
# include <vector>
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
    void    parseStreamTop();


private:
	long			_numCPU;
	std::string		_processes;
	std::string		_time;
	std::string		_loadAvrg;
	std::string		_CPU_usage;
	std::string		_sharedLibs;
	std::string		_memRegions;
	std::string		_physMem;
	std::string		_VM;
	std::string		_networks;
	std::string		_disks;
};

#endif
