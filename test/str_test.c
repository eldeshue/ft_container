
// cc str_test.c -L../ft_String -lftstring -o str_test
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../ft_string/ft_string.h"

int main()
{
	// add
	t_ft_string *test_str1 = new_ftstr_cstr("hello World");
	t_ft_string *test_str2 = new_ftstr_cstr("");
	for (int i = 0; i < 26; ++i)
		test_str1->add(test_str1, test_str2);
	// join
	t_ft_string *test_str3 = test_str1->join(test_str1, test_str2);
	printf("%lu\n%lu\n%lu\n", test_str1->capacity,  test_str2->capacity, test_str3->capacity);
	char *return_string1 = test_str1->c_str(test_str1);
	char *return_string2 = test_str2->c_str(test_str2);
	char *return_string3 = test_str3->c_str(test_str3);
	// append, copy
	printf("%s\n%s\n%s\n", return_string1,  return_string2, return_string3);
	t_ft_string *append_test_str = new_ftstr_copy(test_str2);
	append_test_str->append(append_test_str, " appended ");
	printf("%s\n", append_test_str->c_str(append_test_str));
	// substr
	t_ft_string *test_str4 = test_str1->substr(test_str1, 0, 5);
	printf("%s\n", test_str4->c_str(test_str4));
	// getline
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
