#include <iostream>

const int N = 1e5 + 10;
int a[N];
int n, q;

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d", &q);
	while (q--) {
		int flag, k, x;
		scanf("%d%d", &flag, &k);
		if (flag == 1) {
			scanf("%d", &x);
		 	a[k] = x;
		} else {
			printf("%d\n", a[k]);
		}
	}
	return 0;
}
