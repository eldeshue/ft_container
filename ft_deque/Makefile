# result file name
NAME = libftdeque.a

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -src

SRCS = ft_deque_access.c ft_deque_control.c ft_deque_push.c \
	ft_deque_construct.c ft_deque_new.c ft_deque_set_member_function.c \
	ft_dqnode.c \

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
