//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "CPUModule.hpp"


// Constructors and destructor

CPUModule::CPUModule() {
    _processes = "0";
    _CPU_usage = "0";
    _CPU_user_usage = 0;
    _CPU_sys_usage = 0;
    _model = "0";
}

CPUModule::~CPUModule() {}

CPUModule::CPUModule(CPUModule const &src)
{
	*this = src;
}


// Operators:

CPUModule	&CPUModule::operator=(CPUModule const &src) {
	if (this != &src)
	{
		_numCPU = src.getNumCPU();
		_model = src.getModelCPU();
	}
	return (*this);
}


// Getters:

std::string CPUModule::getProcesses() const {
    return _processes;
}

std::string CPUModule::getCPU_usage() const{
    return _CPU_usage;
}

double CPUModule::getCPU_user_usage() const {
    return _CPU_user_usage;
}

double CPUModule::getCPU_sys_usage() const {
    return _CPU_sys_usage;
}

std::string CPUModule::getModelCPU() const {
    return _model;
}

long CPUModule::getNumCPU() const {
    return _numCPU;
}


// Other functions:

void CPUModule::get_info(Parser_CPU_RAM_Time_Net const &info) {
    _processes = info.getProcesses();
    _CPU_usage = info.getCPU_usage();
    _CPU_user_usage = info.getCPU_user_usage();
    _CPU_sys_usage = info.getCPU_sys_usage();
    _model = info.getModelCPU();
    _numCPU = info.getNumCPU();
}
