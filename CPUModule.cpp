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
    parseStreamTop_OneCircle();

}

void CPUModule::parseStreamTop_OneCircle() {
    FILE * in;
    char buff[256];
    std::string CPU_info;
    size_t iFirst = 0;
    size_t iSecond = 0;

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
    iSecond = CPU_info.find_first_of('\n', iFirst);
    _processes = CPU_info.substr(iFirst, iSecond - iFirst);

    iFirst = CPU_info.find_first_of("2017/", iSecond);
    iSecond = CPU_info.find_first_of('\n', iFirst);
    _time = CPU_info.substr(iFirst, iSecond - iFirst);

    iFirst = CPU_info.find("CPU usage:", iSecond);
    iSecond = CPU_info.find_first_of('\n', iFirst);
    _CPU_usage = CPU_info.substr(iFirst, iSecond - iFirst);

    iFirst = CPU_info.find("PhysMem:", iSecond);
    iSecond = CPU_info.find_first_of('\n', iFirst);
    _RAM = CPU_info.substr(iFirst, iSecond - iFirst);

    iFirst = CPU_info.find("Networks:", iSecond);
    iSecond = CPU_info.find_first_of('\n', iFirst);
    _networks = CPU_info.substr(iFirst, iSecond - iFirst);

    parseCPU_usage();
    parseRAM_usage();
    std::cout << _processes << std::endl;
    std::cout << _time << std::endl;
    std::cout << _CPU_usage << std::endl;
    std::cout << _RAM << std::endl;
    std::cout << _networks << std::endl;
}

void CPUModule::parseCPU_usage() {

    std::string userUsageStr = _CPU_usage.substr(11, 6);
    size_t i = _CPU_usage.find("user,", 15);
    std::string sysUsageStr = _CPU_usage.substr(i + 6, 6);

    std::cout << "userUsageStr " << userUsageStr << std::endl;
    std::cout << "sysUsageStr " << sysUsageStr << std::endl;

    _CPU_user_usage = atof(userUsageStr.c_str());
    _CPU_sys_usage = atof(sysUsageStr.c_str());

    std::cout << "userUsageStr " << _CPU_user_usage << std::endl;
    std::cout << "sysUsageStr " << _CPU_sys_usage << std::endl;
}

void CPUModule::parseRAM_usage() {

    std::string RAM_usedStr = _RAM.substr(9, 6);
    size_t i = _RAM.find("wired),", 15);
    std::string RAM_unusedStr = _RAM.substr(i + 8, 6);

    std::cout << "RAM_usedStr " << RAM_usedStr << std::endl;
    std::cout << "RAM_unusedStr " << RAM_unusedStr << std::endl;

    _RAM_used = atoi(RAM_usedStr.c_str());
    _RAM_unused = atoi(RAM_unusedStr.c_str());

    std::cout << "_RAM_used " << _RAM_used << std::endl;
    std::cout << "_RAM_unused " << _RAM_unused << std::endl;
}













