//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"
#include "OS_Info.hpp"
#include <cstdlib>

int			main(void)
{
//	HostUserName	hu;
//	std::cout << "username: " << hu.getUserName() << std::endl;
//	std::cout << "hostname: " << hu.getHostName() << std::endl;


	FILE *in;
	char buff[256];

	if(!(in = popen("top -l 1 -n 0 -s 0", "r"))){
		return 1;
	}
	while(fgets(buff, sizeof(buff), in)!=NULL){
		std::cout << buff;
	}
	pclose(in);

	OS_Info osInfo;
	return (0);
}
