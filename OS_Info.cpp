//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "OS_Info.hpp"

OS_Info::OS_Info() {
    _flag = true;
    _productName = "0";
    _productVersion = "0";
    _buildVersion = "0";
    _productCopyright = "0";
}

OS_Info::~OS_Info() {
}

std::string		OS_Info::getProductName() const {
    return (_productName);
}

std::string		OS_Info::getProductVersion() const {
    return (_productVersion);
}

std::string		OS_Info::getbuildVersion() const {
    return (_buildVersion);
}

std::string OS_Info::getproductCopyright() const {
    return _productCopyright;
}

bool        OS_Info::getFlag() const {
    return _flag;
}

void OS_Info::setProductName(std::string ProdName) {
    _productName = ProdName;
}

void OS_Info::setProductVersion(std::string ProdVer) {
    _productVersion = ProdVer;
}

void OS_Info::setBuildVersion(std::string buildVer) {
    _buildVersion = buildVer;
}

void OS_Info::setProductCopyright(std::string ProdCopiright) {
    _productCopyright = ProdCopiright;
}

void			OS_Info::get_info(Parser_CPU_RAM_Time_Net const &info)
{
    std::string     line;
    std::string     buf;
    std::ifstream   inStream;
    std::string     file_name = "/System/Library/CoreServices/SystemVersion.plist";

    inStream.exceptions(std::ifstream::failbit);
    try {
        inStream.open(file_name);
        while ( std::getline (inStream, buf) )
        {
            line += buf;
            if (! inStream.eof())
                line += "\n";
        }
        inStream.close();
    }
    catch (const std::exception& e) {
        std::ostringstream msg;
        msg << "Opening file '" << file_name
            << "' failed, it either doesn't exist or is not accessible.";
        throw std::runtime_error(msg.str());
    }

    std::vector< std::pair<std::string, std::string> > v;
    size_t iFirst = 0;
    size_t iSecond = 0;
    std::pair<std::string, std::string> myPair;

    for (int i = 0; i < 4; i++) {

        iFirst = line.find("<key>", iFirst);
        iSecond = line.find("</key>", iSecond);
        iFirst += 5;
        myPair.first = line.substr(iFirst, iSecond - iFirst);

        iFirst = line.find("<string>", iFirst);
        iSecond = line.find("</string>", iSecond);
        iFirst += 8;
        myPair.second = line.substr(iFirst, iSecond - iFirst);
        v.push_back(myPair);
        // std::cout << myPair.first << " " <<  myPair.second << std::endl;
    }

    _buildVersion = v.at(0).second;
    _productCopyright = v.at(1).second;
    _productName = v.at(2).second;
    _productVersion = v.at(3).second;
    _flag = info.getFlag();
}
