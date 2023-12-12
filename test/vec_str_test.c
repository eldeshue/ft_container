// cc vec_str_test.c -L../ft_vector -lftvector -L../ft_string -lftstring -o vec_str_test

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_vector/ft_vector.h"
#include "../ft_string/ft_string.h"
void check_leak(void);

int construct_ft_string_in_vec(void *paddr, void *literal)
{
	*(t_ft_string *)paddr = construct_ftstr_cstr((char *)literal);
	return (1);
}

void destruct_ft_string_in_vec(void *paddr)
{
	destruct_ftstr((t_ft_string *)paddr);
}

void print_all(t_ft_vector *str_vec)
{
	for (int i = 0; i < str_vec->size; ++i)
	{
		//printf("%d : ", i);
		write(1, (*(t_ft_string *)(str_vec->at(str_vec, i))).pbuffer,
		(*(t_ft_string *)(str_vec->at(str_vec, i))).size);
		write(1, "\n", 1);
	}
}

int main()
{
	char *str1 = "start";
	char *str2 = "hello world";
	char *str3 = "end";

	// constructor test
	printf("call constructor\n");
	t_ft_vector str_vec = construct_ftvec(construct_ft_string_in_vec,
		destruct_ft_string_in_vec, sizeof(t_ft_string));
	printf("check is empty : %d \n", str_vec.empty(&str_vec));

	// push_back test
	printf("call push_back\n");
	str_vec.push_back(&str_vec, str1);
	for (int i = 0; i < 12; ++i)
		str_vec.push_back(&str_vec, str2);
	str_vec.push_back(&str_vec, str3);

	// content check
	printf("call at, check content.\n");
	print_all(&str_vec);

	// resize
	printf("call resize, change to 5, check content.\n");
	str_vec.resize(&str_vec, 5);
	print_all(&str_vec);
	printf("check is empty : %d \n", str_vec.empty(&str_vec));

	// clear
	/*
	printf("call clear, check content.\n");
	str_vec->clear(str_vec);
	print_all(str_vec);
	printf("check is empty : %d \n", str_vec->empty(str_vec));
	*/

	// destruct vector
	printf("calling destructor.\n");
	destruct_ftvec(&str_vec);

	printf("========================\n");
	atexit(check_leak);
	return (0);
}

void check_leak(void)
{
	system("leaks --list -- vec_str_test");
}
