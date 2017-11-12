//
// Created by Roman Malkevych on 11/12/17.
//

#include "NetworkModule.hpp"


// Constructors and destructor

NetworkModule::NetworkModule() {
    _networks = "0";
}

NetworkModule::~NetworkModule() {}

NetworkModule::NetworkModule(NetworkModule const &src)
{
    *this = src;
}


// Operators:

NetworkModule	&NetworkModule::operator=(NetworkModule const &src) {
    if (this != &src)
    {
        _networks = src.getNetworks();
    }
    return (*this);
}


// Getters:

std::string	const   &NetworkModule::getNetworks() const {
    return _networks;
}


// Other functions:

void    NetworkModule::get_info(Parser_CPU_RAM_Time_Net const &info) {
    _networks = info.getNetworks();
}
