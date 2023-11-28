# result file name
NAME = libftdeque.a

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -src

SRCS = ft_deque.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
