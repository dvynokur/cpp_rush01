//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef HOSTUSERNAME_HPP
# define HOSTUSERNAME_HPP

# include "ft_gkrellm.hpp"

class HostUserName : public IMonitorModule
{
public:
	HostUserName();
	HostUserName(HostUserName const &src);
	~HostUserName();
	HostUserName	&operator=(HostUserName const &src);
	void			get_info(void);
	class HostUserNameException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Hostname or username error");
		};
	};

	std::string		getHostName(void) const;
	std::string		getUserName(void) const;

	void			setHostName(std::string hn);
	void			setUserName(std::string un);

private:
	std::string		_hostname;
	std::string		_username;
};

#endif
