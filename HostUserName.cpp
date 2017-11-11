//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "HostUserName.hpp"

HostUserName::HostUserName(void) {
	this->get_info();
	return ;
}

HostUserName::~HostUserName(void) {
	return ;
}

HostUserName::HostUserName(HostUserName const & src)
{
	*this = src;
	return ;
}

HostUserName	&HostUserName::operator=(HostUserName const &src)
{
	if (this != &src)
	{
		this->_hostname = src.getHostName();
		this->_username = src.getUserName();
	}
	return (*this);
}


std::string		HostUserName::getHostName(void) const {
	return (this->_hostname);
}
std::string		HostUserName::getUserName(void) const {
	return (this->_username);
}

void			HostUserName::setHostName(std::string hn) {
	this->_hostname = hn;
	return ;
}
void			HostUserName::setUserName(std::string un) {
	this->_username = un;
	return ;
}

void			HostUserName::get_info(void)
{
	char hostname[MAX_NAME];
	char username[MAX_NAME];
	int result;
	try
	{
		result = gethostname(hostname, MAX_NAME);
		if (result)
			throw HostUserNameException();
		this->setHostName(hostname);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		result = getlogin_r(username, MAX_NAME);
		if (result)
			throw HostUserNameException();
		this->setUserName(username);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
