NAME = philo
CC = cc 
CFLAG = -Wall -Werror -Wextra -pthread

SRCS =	behav.c creat_util.c init.c io_exit.c \
		philo.c time.c monitor.c 

OBJS =	$(SRCS:.c=.o)

#SANITIZER = -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) $(SANITIZER)

%.o: %.c philo.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
