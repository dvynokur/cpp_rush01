//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef OS_INFO_HPP
# define OS_INFO_HPP

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
# include "ft_gkrellm.hpp"

class OS_Info : public IMonitorModule
{
public:
    OS_Info();
    ~OS_Info();
    void			get_info();
    class OS_InfoException : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return ("OS_Info error");
        };
    };

    std::string		getProductName() const;
    std::string		getProductVersion() const;
    std::string		getbuildVersion() const;
    std::string		getproductCopyright() const;

    void			setProductName(std::string ProdName);
    void			setProductVersion(std::string ProdVer);
    void    		setBuildVersion(std::string buildVer);
    void            setProductCopyright(std::string ProdCopiright);

private:
    std::string		_productName;
    std::string     _productVersion;
    std::string     _buildVersion;
    std::string     _productCopyright;
};

#endif
