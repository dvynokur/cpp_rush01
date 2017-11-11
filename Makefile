CXX			= clang++
# CXXFLAGS	= -Wall -Wextra -Werror
FILES		= main.cpp HostUserName.cpp DateTimeModule
NAME		= ft_gkrellm
OFILES		= main.o HostUserName.o DateTimeModule.o

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