CXX			= clang++
# CXXFLAGS	= -Wall -Wextra -Werror

FILES		= main.cpp HostUserName.cpp DateTimeModule.cpp OS_Info.cpp CPUModule.cpp DisplayHostUserName.cpp DisplayOSInfo.cpp DisplayDateTime.cpp DisplayCPU.cpp DisplayRAM.cpp DisplayNetwork.cpp NetworkModule.cpp RAM_Module.cpp Parser_CPU_RAM_Time_Net.cpp
NAME		= ft_gkrellm
OFILES		= main.o HostUserName.o DateTimeModule.o OS_Info.o CPUModule.o DisplayHostUserName.o DisplayOSInfo.o DisplayDateTime.o DisplayCPU.o DisplayRAM.o DisplayNetwork.o NetworkModule.o RAM_Module.o Parser_CPU_RAM_Time_Net.o

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