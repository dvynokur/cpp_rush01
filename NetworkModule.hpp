//
// Created by Roman Malkevych on 11/12/17.
//

#ifndef RUSH01_NETWORKMODULE_HPP
#define RUSH01_NETWORKMODULE_HPP

# include "ft_gkrellm.hpp"

class NetworkModule : public IMonitorModule
{
public:
    NetworkModule();
    ~NetworkModule();

    void			get_info(Parser_CPU_RAM_Time_Net const &info);

    // getters:
    std::string	const   &getNetworks() const;


private:
    NetworkModule(NetworkModule const &src);
    NetworkModule	&operator=(NetworkModule const &src);

    std::string		_networks;
};

#endif //RUSH01_NETWORKMODULE_HPP
