//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef RUSH01_PARSER_CPU_RAM_TIME_NETWORK_HPP
# define RUSH01_PARSER_CPU_RAM_TIME_NETWORK_HPP

# include "ft_gkrellm.hpp"
# include <cstdlib>
# include <exception>
# include <vector>
# include <sstream>
# include <iostream>

class Parser_CPU_RAM_Time_Net {
public:
    Parser_CPU_RAM_Time_Net();
    ~Parser_CPU_RAM_Time_Net();

    void			get_info();

    // *** GETTERS *** //
    std::string	const   &getProcesses() const;
  std::string	const   &getTime() const;
    std::string	const   &getCPU_usage() const;
    double              getCPU_user_usage() const;
    double              getCPU_sys_usage() const;
    std::string	const   &getRAM() const;
    int                 getRAM_used() const;
    int                 getRAM_unused() const;
    std::string	const   &getNetworks() const;
    std::string	const   &getModelCPU() const;
    long                getNumCPU() const;
    bool                getFlag() const;

private:
    Parser_CPU_RAM_Time_Net(Parser_CPU_RAM_Time_Net const &parser);
    Parser_CPU_RAM_Time_Net &operator=(Parser_CPU_RAM_Time_Net const & parser);

    void            parseStreamTop_OneCircle(); // Parse CPU RAM Time from 'top' command
    void            parseCPU_usage();
    void            parseRAM_usage();

    std::string		_processes;
    std::string		_time;
    std::string		_CPU_usage;
    double          _CPU_user_usage;
    double          _CPU_sys_usage;
    std::string		_RAM;
    int             _RAM_used;
    int             _RAM_unused;
    std::string		_networks;

    bool 			_flag;
};


#endif //RUSH01_PARSER_CPU_RAM_TIME_NETWORK_HPP
