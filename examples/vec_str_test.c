
/*
	example of using ft_vector with ft_string

	cc vec_str_test.c -L../ft_vector -lftvector -L../ft_string -lftstring -o vec_str_test
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_vector/ft_vector.h"
#include "../ft_string/ft_string.h"

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
	t_ft_string *temp;
	for (int i = 0; i < str_vec->size; ++i)
	{
		temp = str_vec->at(str_vec, i);
		printf("%d\'th content : %s\n", i, temp->c_str(temp));
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
	printf("========================\n");

	// push_back test
	printf("call push_back\n");
	str_vec.push_back(&str_vec, str1);
	for (int i = 0; i < 12; ++i)
		str_vec.push_back(&str_vec, str2);
	str_vec.push_back(&str_vec, str3);

	// content check
	printf("call at, check content.\n");
	print_all(&str_vec);
	printf("========================\n");

	// resize
	printf("call resize, change to 5, check content.\n");
	str_vec.resize(&str_vec, 5);
	print_all(&str_vec);
	printf("check is empty : %d \n", str_vec.empty(&str_vec));
	printf("========================\n");

	// clear
	printf("call clear, check content.\n");
	str_vec.clear(&str_vec);
	print_all(&str_vec);
	printf("check is empty : %d \n", str_vec.empty(&str_vec));
	printf("========================\n");

	// destruct vector
	printf("calling destructor.\n");
	destruct_ftvec(&str_vec);
	return (0);
}
