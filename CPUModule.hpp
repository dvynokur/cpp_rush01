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
	void			get_info();

	class CPUModuleException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("CPUModule read error");
		};
	};

	void			PModel(void);

	// setters:

	void			setModel(std::string s);
	void			setNumCPU(int n);

	// getters:



	std::string		getModel(void) const;
	int				getNumCPU(void) const;


private:
    void            parseStreamTop_OneCircle();
    void            parseCPU_usage();
    void            parseRAM_usage();

	std::string		_model;
	std::string		_processes;
	std::string		_time;
	std::string		_CPU_usage;
    double          _CPU_user_usage;
    double          _CPU_sys_usage;
	std::string		_RAM;
    int             _RAM_used;
    int             _RAM_unused;
	std::string		_networks;

    long            _numCPU;
};

#endif
