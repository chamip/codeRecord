#include <iostream>

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d%d", &a, &b);
	int res = 1;
	while (b--) res *= a;
	printf("%d\n", res);
	return 0;
}