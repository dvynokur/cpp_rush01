//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "CPUModule.hpp"

// Constructors and destructor

CPUModule::CPUModule(void) {
	this->get_info();
	// std::cout << RED << this->getNumCPU() << RESET << std::endl;
	return ;
}

CPUModule::~CPUModule(void) {
	return ;
}

CPUModule::CPUModule(CPUModule const &src)
{
	*this = src;
	return ;
}

// operators:

CPUModule	&CPUModule::operator=(CPUModule const &src) {
	if (this != &src)
	{
		this->_numCPU = src.getNumCPU();
		this->_model = src.getModel();
	}
	return (*this);
}

// setters:


void			CPUModule::setModel(std::string s) {
	this->_model = s;
	return ;
}

void			CPUModule::setNumCPU(int n) {
	this->_numCPU = n;
	return ;
}

// getters:

std::string		CPUModule::getModel(void) const {
	return (this->_model);
}

int				CPUModule::getNumCPU(void) const {
	return (this->_numCPU);
}


// other functions:

void			CPUModule::PModel(void)
{
	FILE 			*in;
	char 			buff[512];
	std::string 	string_in("");
	
	try
	{
		if(!(in = popen("sysctl -n machdep.cpu.brand_string", "r")))
			throw CPUModuleException();
		fgets(buff, sizeof(buff), in);
		this->setModel(buff);
		pclose(in);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void			CPUModule::get_info(void)
{
	this->setNumCPU(sysconf(_SC_NPROCESSORS_ONLN));
	this->PModel();
	return ;
}
