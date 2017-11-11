//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define BLACK		"\x1b[37m"
# define RESET		"\x1b[0m"
# define BOLD_ON	"\x1b[1m"
# define BOLD_OFF	"\x1b[22m"


# define MAX_NAME 100

# include <iostream>
# include <unistd.h>
# include <limits.h>

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

#	include "HostUserName.hpp"


#endif
