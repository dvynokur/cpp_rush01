//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"


int			main(void)
{
	HostUserName	hu;
	std::cout << "username: " << hu.getUserName() << std::endl;
	std::cout << "hostname: " << hu.getHostName() << std::endl;

	DateTimeModule	dt;

	std::cout << "year: " << dt.getYear() << std::endl;
	std::cout << "month: " << dt.getMonth() << std::endl;
	std::cout << "day: " << dt.getDay() << std::endl;
	std::cout << "hour: " << dt.getHour() << std::endl;
	std::cout << "minutes: " << dt.getMinutes() << std::endl;
	std::cout << "seconds: " << dt.getSeconds() << std::endl;
	return (0);
}
