//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "CPUMode.hpp"

// Constructors and destructor

CPUMode::CPUMode(void) {
	this->get_info();
	return ;
}

CPUMode::~CPUMode(void) {
	return ;
}

CPUMode::CPUMode(CPUMode const &src)
{
	*this = src;
	return ;
}

// operators:

CPUMode	&CPUMode::operator=(CPUMode const &src) {
	if (this != &src)
	{
		this->_numCPU = sysconf(_SC_NPROCESSORS_ONLN);
	}
	return (*this);
}
