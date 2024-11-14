
/*
	example of using ft_string

	cc str_test.c -L../ft_string -lftstring -o str_test
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../ft_string/ft_string.h"

int main()
{
	// constructioin
	printf("------------- string construction -----------\n");
	t_ft_string *test_str1 = new_ftstr_cstr("hello World");
	t_ft_string *test_str2 = new_ftstr_cstr("1");
	printf("test_str1 : %s\ntest_str2 : %s\n", test_str1->c_str(test_str1), test_str2->c_str(test_str2));

	// string add
	printf("------------- string add -----------\n");
	for (int i = 1; i < 6; ++i)
	{
		test_str1->add(test_str1, test_str2);
		printf("add test_str2 to test_str1, %d times : %s\n", i, test_str1->c_str(test_str1));
	}

	// string join
	printf("------------- string join -----------\n");
	t_ft_string *test_str3 = test_str1->join(test_str1, test_str1);
	const char *return_string3 = test_str3->c_str(test_str3);
	printf("Joined str, test_str3 : %s\n", return_string3);

	// append, copy
	printf("------------- string append -----------\n");
	t_ft_string *append_test_str = new_ftstr_copy(test_str2);
	printf("before append, copy test_str2 : %s\n", append_test_str->c_str(append_test_str));
	append_test_str->append(append_test_str, " appended ");
	printf("after append : %s\n", append_test_str->c_str(append_test_str));

	// substr
	printf("------------- substr-----------\n");
	t_ft_string *test_str4 = test_str1->substr(test_str1, 0, 5);
	printf("%s\n", test_str4->c_str(test_str4));

	// getline test
	printf("------------- getline from file -----------\n");
	int test_fd = open("./getline_test.txt", O_RDONLY);
	t_ft_string *test_str5 = new_ftstr();
	test_str4->getline(test_str5, test_fd);
	printf("%s\n", test_str5->c_str(test_str5));
	test_str4->getline(test_str5, test_fd);
	printf("%s\n", test_str5->c_str(test_str5));
	test_str4->getline(test_str5, test_fd);
	printf("%s\n", test_str5->c_str(test_str5));
	close(test_fd);
}
