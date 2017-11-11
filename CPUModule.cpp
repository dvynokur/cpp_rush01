//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include <sstream>
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


void CPUModule::get_info() {

    this->setNumCPU(sysconf(_SC_NPROCESSORS_ONLN));
    this->PModel();
    return ;


    FILE * in;
    char buff[256];
    std::string CPU_info;
    size_t iFirst = 0;
    size_t iSecond = 0;
    std::vector<std::string> v;

    while (1) {
        try {
            if(!(in = popen("top -l 1 -n 0 -s 0", "r"))) {
                throw std::runtime_error("Could not read from console");;
            }
            while(fgets(buff, sizeof(buff), in) != nullptr) {
                CPU_info += buff;
            }
            pclose(in);
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        iFirst = CPU_info.find("Processes:", iFirst);
        iSecond = CPU_info.find('\n', iSecond + 1);
        _processes = CPU_info.substr(iFirst, iSecond - iFirst);

        iFirst = CPU_info.find("CPU usage:", iFirst);
        iSecond = CPU_info.find('\n', iSecond  + 1);
        _CPU_usage = CPU_info.substr(iFirst, iSecond - iFirst);

        iFirst = CPU_info.find("PhysMem:", iFirst);
        iSecond = CPU_info.find('\n', iSecond + 1);
        _physMem = CPU_info.substr(iFirst, iSecond - iFirst);

        iFirst = CPU_info.find("Networks:", iFirst);
        iSecond = CPU_info.find('\n', iSecond + 1);
        _networks = CPU_info.substr(iFirst, iSecond - iFirst);

        std::cout << _processes << std::endl;
        std::cout << _CPU_usage << std::endl;
        std::cout << _physMem << std::endl;
        std::cout << _networks << std::endl;

        usleep(50000000);
    }
}
