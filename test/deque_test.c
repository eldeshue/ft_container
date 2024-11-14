
/*
	example of using ft_deque with ft_string

	cc deque_test.c -L../ft_deque -lftdeque -L../ft_string -lftstring -o deque_test
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_deque/ft_deque.h"
#include "../ft_string/ft_string.h"

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

int main()
{
	t_ft_string *pFrontStr, *pBackStr;

	// constructor test
	printf("call constructor\n");
	t_ft_deque str_deque = construct_ftdeque(construct_ft_string_in_deque,
											 destruct_ft_string_in_deque, sizeof(t_ft_string));
	printf("check is empty : %d \n", str_deque.empty(&str_deque));
	printf("========================\n");

	// push test
	printf("call push_back, insert \'start\'\n");
	str_deque.push_back(&str_deque, "start");
	printf("check is empty : %d \n", str_deque.empty(&str_deque));
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	printf("call push_back, insert \'hello world\'\n");
	str_deque.push_back(&str_deque, "hello world");
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	printf("call push_back, insert \'end\'\n");
	str_deque.push_back(&str_deque, "end");
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	printf("call push_front, insert \'hello world\'\n");
	str_deque.push_front(&str_deque, "hello world");
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	printf("call push_front, \'start\'\n");
	str_deque.push_front(&str_deque, "start");
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	// clear check
	printf("call clear, check content.\n");
	str_deque.clear(&str_deque);
	printf("check is empty : %d \n", str_deque.empty(&str_deque));
	printf("========================\n");

	// push after clear
	printf("call push_back, insert \'start\'\n");
	str_deque.push_back(&str_deque, "start");
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	printf("call push_front, insert \'end\'\n");
	str_deque.push_front(&str_deque, "end");
	pFrontStr = str_deque.front(&str_deque);
	pBackStr = str_deque.back(&str_deque);
	printf("front is : %s\n", pFrontStr->c_str(pFrontStr));
	printf("back is : %s\n", pBackStr->c_str(pBackStr));
	printf("========================\n");

	// destruct vector
	printf("calling destructor.\n");
	destruct_ftdeque(&str_deque);
	printf("========================\n");
	return (0);
}
