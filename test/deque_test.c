
// gcc deque_test.c -L../ft_deque -lftdeque -L../ft_string -lftstring -o deque_test

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_deque/ft_deque.h"
#include "../ft_string/ft_string.h"
void check_leak(void);

int construct_ft_string_in_deque(void *paddr, void *literal)
{
	*(t_ft_string *)paddr = construct_ftstr_cstr((char *)literal);
	if (paddr == NULL)
		return (0);
	return (1);
}

void destruct_ft_string_in_deque(void *paddr)
{
	destruct_ftstr((t_ft_string *)paddr);
}

void print_ft_string_nl(t_ft_string *str)
{
	write(1, (str)->pbuffer, (str)->size);
	write(1, "\n", 1);
}
int main()
{
	char *str1 = "start";
	char *str2 = "hello world";
	char *str3 = "end";

	// constructor test
	printf("call constructor\n");
	t_ft_deque str_deque = construct_ftdeque(construct_ft_string_in_deque,
											  destruct_ft_string_in_deque, sizeof(t_ft_string));
	printf("check is empty : %d \n", str_deque.empty(&str_deque));

	// push test
	printf("call push_back\n");
	str_deque.push_back(&str_deque, str1);
	printf("check is empty : %d \n", str_deque.empty(&str_deque));
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	printf("call push_back\n");
	str_deque.push_back(&str_deque, str2);
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	printf("call push_back\n");
	str_deque.push_back(&str_deque, str3);
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	printf("call push_front\n");
	str_deque.push_front(&str_deque, str2);
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	printf("call push_front\n");
	str_deque.push_front(&str_deque, str1);
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	// clear check
	printf("call clear, check content.\n");
	str_deque.clear(&str_deque);
	printf("check is empty : %d \n", str_deque.empty(&str_deque));

	printf("call push_back\n");
	str_deque.push_back(&str_deque, str3);
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	printf("call push_front\n");
	str_deque.push_front(&str_deque, str2);
	printf("front is : ");
	print_ft_string_nl(str_deque.front(&str_deque));
	printf("back is : ");
	print_ft_string_nl(str_deque.back(&str_deque));

	// destruct vector
	printf("calling destructor.\n");
	destruct_ftdeque(&str_deque);

	printf("========================\n");
	atexit(check_leak);
	return (0);
}

void check_leak(void)
{
	system("leaks --list -- deque_test");
}
