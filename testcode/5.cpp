#include <iostream>

int main(int argc, char const *argv[])
{
	char *s = "abcd";
	char *s1 = s;
	printf("total:%d characters, start with \'%c\'.\n", strlen(s1), s[0]);
	return 0;
}