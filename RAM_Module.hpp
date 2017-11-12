//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef RUSH01_RAM_MODULE_HPP
#define RUSH01_RAM_MODULE_HPP

# include "ft_gkrellm.hpp"

class RAM_Module : public IMonitorModule
{
public:
    RAM_Module();
    ~RAM_Module();

    void			get_info(Parser_CPU_RAM_Time_Net const &info);

    // getters:
    std::string	const   &getRAM() const;
    int                 getRAM_used() const;
    int                 getRAM_unused() const;


private:
    RAM_Module(RAM_Module const &src);
    RAM_Module	&operator=(RAM_Module const &src);

    std::string		_RAM;
    int             _RAM_used;
    int             _RAM_unused;
};

#endif //RUSH01_RAM_MODULE_HPP
