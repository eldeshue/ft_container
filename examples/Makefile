# result file name
STRING_SAMPLE = string_sample
VEC_WITH_STRING_SAMPLE = vector_with_string_sample
VEC_WITH_CUSTOM_SAMPLE = vector_with_custom_sample
DEQUEUE_WITH_STRING_SAMPLE = deque_with_string_sample

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(STRING_SAMPLE) $(VEC_WITH_STRING_SAMPLE) $(VEC_WITH_CUSTOM_SAMPLE) $(DEQUEUE_WITH_STRING_SAMPLE)

STRING_DIR = ../ft_string
VECTOR_DIR = ../ft_vector
DEQUEUE_DIR = ../deque

$(STRING_SAMPLE) :
	$(MAKE) -C ../ft_string
	$(CC) $(CFLAGS) str_test.c -L../ft_string -lftstring -o $@

$(VEC_WITH_STRING_SAMPLE) :
	$(MAKE) -C ../ft_string
	$(MAKE) -C ../ft_vector
	$(CC) $(CFLAGS) vec_str_test.c -L../ft_string -lftstring -L../ft_vector -lftvector -o $@

$(VEC_WITH_CUSTOM_SAMPLE) :
	$(MAKE) -C ../ft_vector
	$(CC) $(CFLAGS) vec_test.c -L../ft_vector -lftvector -o $@

$(DEQUEUE_WITH_STRING_SAMPLE ) :
	$(MAKE) -C ../ft_string
	$(MAKE) -C ../ft_deque
	$(CC) $(CFLAGS) deque_test.c -L../ft_deque -lftdeque -L../ft_string -lftstring -o $@

clean:
	$(MAKE) -C $(STRING_DIR) clean
	$(MAKE) -C $(VECTOR_DIR) clean
	$(MAKE) -C $(DEQUEUE_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
