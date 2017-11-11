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
	int				_numCPU;
	std::string		_model;
};

#endif
