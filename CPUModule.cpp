//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include <sstream>
#include "CPUModule.hpp"

// Constructors and destructor

CPUModule::CPUModule(void) {
	this->get_info();
	return ;
}

CPUModule::~CPUModule() {

}

CPUModule::CPUModule(CPUModule const &src)
{
	*this = src;
}

// operators:

CPUModule	&CPUModule::operator=(CPUModule const &src) {
	if (this != &src)
	{
		this->_numCPU = sysconf(_SC_NPROCESSORS_ONLN);
	}
	return (*this);
}

void CPUModule::get_info() {

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