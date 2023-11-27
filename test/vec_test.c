// cc vec_test.c -L../FT_Vector -lftvector -o vec_test
#include <stdio.h>
#include <stdlib.h>
#include "../FT_Vector/ft_vector.h"

typedef struct test_struct
{
	int number;
	char *str;
} t_test;

struct param_test
{
	int n;
	char *str;
};

int construct_test(void *paddr, void *pparam)
{
	((t_test *)paddr)->number = ((struct param_test *)pparam)->n;
	((t_test *)paddr)->str = malloc(((struct param_test *)pparam)->n * sizeof(char));
	if (((t_test *)paddr)->str == NULL)
	{
		return (0);
	}
	for (int i = 0; i < ((struct param_test *)pparam)->n; ++i)
	{
		((t_test *)paddr)->str[i] = ((struct param_test *)pparam)->str[i];
	}
	return (1);
}

void destruct_test(void *paddr)
{
	if (paddr != NULL)
	{
		free(((t_test *)paddr)->str);
	}
}

void check_leak(void)
{
	system("leaks --list -- vec_test");
}

void print_test_vec_all(t_ft_vector *vec)
{
	for (int i = 0; i < vec->size; ++i)
	{
		printf("%s\n", ((t_test *)(vec->at(vec, i)))->str);
	}
}

int main()
{
	// basic check.
	struct param_test param1 = {12, "hello world"};
	struct param_test param2 = {6, "start"};
	struct param_test param3 = {4, "end"};

	// constructor test
	printf("call constructor\n");
	t_ft_vector *test_vec = construct_ftvec(construct_test,
		destruct_test, sizeof(t_test));
	printf("check is empty : %d \n", test_vec->empty(test_vec));

	// push_back test
	printf("call push_back\n");
	test_vec->push_back(test_vec, &param2);
	for (int i = 0; i < 12; ++i)
		test_vec->push_back(test_vec, &param1);
	test_vec->push_back(test_vec, &param3);

	// content check
	printf("call at, check content.\n");
	print_test_vec_all(test_vec);

	// front, back check
	printf("call ft_vector front : %s\n", ((t_test *)(test_vec->front(test_vec)))->str);
	printf("call ft_vector back  : %s\n", ((t_test *)(test_vec->back(test_vec)))->str);

	// resize
	printf("call resize, change to 5, check content.\n");
	test_vec->resize(test_vec, 5);
	print_test_vec_all(test_vec);
	printf("check is empty : %d \n", test_vec->empty(test_vec));

	// clear
	printf("call clear, check content.\n");
	test_vec->clear(test_vec);
	print_test_vec_all(test_vec);	// do nothing
	printf("check is empty : %d \n", test_vec->empty(test_vec));

	// destruct vector
	printf("calling destructor.\n");
	destruct_ftvec(test_vec);

	printf("========================\n");
	atexit(check_leak);
	return (0);
}
