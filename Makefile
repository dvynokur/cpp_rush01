CXX			= clang++
# CXXFLAGS	= -Wall -Wextra -Werror

FILES		= main.cpp HostUserName.cpp DateTimeModule.cpp OS_Info.cpp CPUModule.cpp
NAME		= ft_gkrellm
OFILES		= main.o HostUserName.o DateTimeModule.o OS_Info.o CPUModule.o

all: $(NAME)

$(NAME): $(OFILES)
	clang++  -o $@ $^ -lncurses

%.o: %.c
	clang++ -o $@ -c $< 

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(OFILES)
	rm -f $(NAME)

re: fclean all