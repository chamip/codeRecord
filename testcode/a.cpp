#include <iostream>
#include <vector>
using namespace std;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    Solution *s = new Solution();
	char str[] = "hello";
	char *p = str;
	cout << "sizeof(str): " << sizeof(str) \
		 << ", sizeof(p): " << sizeof(p) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	for (int i = 0; i < sizeof(str); ++i) {
		cout << str + i << " " << *(str + i) << endl;
	}
	return 0;
}
