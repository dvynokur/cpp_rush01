//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "RAM_Module.hpp"


// Constructors and destructor

RAM_Module::RAM_Module() {
    _RAM = "0";
    _RAM_used = 0;
    _RAM_unused = 0;
}

RAM_Module::~RAM_Module() {}

RAM_Module::RAM_Module(RAM_Module const &src)
{
    *this = src;
}


// Operators:

RAM_Module	&RAM_Module::operator=(RAM_Module const &src) {
    if (this != &src)
    {
        _RAM = src.getRAM();
        _RAM_used = src.getRAM_used();
        _RAM_unused = src.getRAM_unused();
    }
    return (*this);
}


// Getters:

std::string	const   &RAM_Module::getRAM() const {
    return _RAM;
}

int     RAM_Module::getRAM_used() const {
    return _RAM_used;
}

int     RAM_Module::getRAM_unused() const {
    return _RAM_unused;
}

// Other functions:

void    RAM_Module::get_info(Parser_CPU_RAM_Time_Net const &info) {
    _RAM = info.getRAM();
    _RAM_used = info.getRAM_used();
    _RAM_unused = info.getRAM_unused();
}
