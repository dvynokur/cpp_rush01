//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "DateTimeModule.hpp"

// Constructors and destructor

DateTimeModule::DateTimeModule(void) {
	this->get_info();
	return ;
}

DateTimeModule::~DateTimeModule(void) {
	return ;
}

DateTimeModule::DateTimeModule(DateTimeModule const &src)
{
	*this = src;
	return ;
}

// operators:

DateTimeModule	&DateTimeModule::operator=(DateTimeModule const &src)
{
	if (this != &src)
	{
		this->_year = src.getYear();
		this->_month = src.getMonth();
		this->_day = src.getDay();
		this->_hour = src.getHour();
		this->_minutes = src.getMinutes();
		this->_seconds = src.getSeconds();
	}
	return (*this);
}


//setters:

void			DateTimeModule::setYear(int n) {
	this->_year = n;
	return ;
}
void			DateTimeModule::setMonth(int n) {
	this->_month = n;
	return ;
}
void			DateTimeModule::setDay(int n) {
	this->_day = n;
	return ;
}
void			DateTimeModule::setHour(int n) {
	this->_hour = n;
	return ;
}
void			DateTimeModule::setMinutes(int n) {
	this->_minutes = n;
	return ;
}
void			DateTimeModule::setSeconds(int n) {
	this->_seconds = n;
	return ;
}


// getters:

int				DateTimeModule::getYear(void) const {
	return (this->_year);
}
int				DateTimeModule::getMonth(void) const {
	return (this->_month);
}
int				DateTimeModule::getDay(void) const {
	return (this->_day);
}
int				DateTimeModule::getHour(void) const {
	return (this->_hour);
}
int				DateTimeModule::getMinutes(void) const {
	return (this->_minutes);
}
int				DateTimeModule::getSeconds(void) const {
	return (this->_seconds);
}


// functions:

void			DateTimeModule::get_info(void)
{
	time_t t = time(0);
	struct tm * now = localtime( & t );

	this->setYear(now->tm_year + 1900);
	this->setMonth(now->tm_mon + 1);
	this->setDay(now->tm_mday);

	this->setHour(now->tm_hour);
	this->setMinutes(now->tm_min);
	this->setSeconds(now->tm_sec);

}
