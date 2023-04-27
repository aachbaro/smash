NAME		= smash
SRCSDIR		= .
OBJSDIR		= objs
INCLUDES	= .
SRCS		= srcs/main.cpp \
				srcs/utils.cpp
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -I/home/aachbaro/Document/smash/include -L/home/aachbaro/sdl/src -lSDL2

all: $(NAME)
$(NAME): $(SRCSDIR)/$(SRCS)
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $^
clean:
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re test