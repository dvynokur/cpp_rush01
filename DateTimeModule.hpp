//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

# include "ft_gkrellm.hpp"

class DateTimeModule : public IMonitorModule
{
public:
	DateTimeModule();
	~DateTimeModule();
	DateTimeModule(DateTimeModule const &src);
	DateTimeModule	&operator=(DateTimeModule const &src);
	void			get_info(void);
	class DateTimeException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Date/time error");
		};
	};

	// setters:

	void			setYear(int n);
	void			setMonth(int n);
	void			setDay(int n);
	void			setHour(int n);
	void			setMinutes(int n);
	void			setSeconds(int n);

	// getters:

	int				getYear(void) const;
	int				getMonth(void) const;
	int				getDay(void) const;
	int				getHour(void) const;
	int				getMinutes(void) const;
	int				getSeconds(void) const;

private:
	int				_year;
	int				_month;
	int				_day;

	int				_hour;
	int				_minutes;
	int				_seconds;
};

#endif
