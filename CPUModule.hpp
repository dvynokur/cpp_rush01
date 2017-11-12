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

	void			get_info(Parser_CPU_RAM_Time_Net const &info);

	// getters:
	std::string		getProcesses() const;
	std::string		getCPU_usage() const;
	double          getCPU_user_usage() const;
	double          getCPU_sys_usage() const;
	std::string		getModelCPU() const;
	long            getNumCPU() const;
	void    		Find_CPUModel_Cores(void);



private:
	CPUModule(CPUModule const &src);
	CPUModule	&operator=(CPUModule const &src);

	std::string		_processes;
	std::string		_CPU_usage;
    double          _CPU_user_usage;
    double          _CPU_sys_usage;
	std::string		_model;
    long            _numCPU;
};

#endif
