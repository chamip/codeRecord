#include <iostream>
#include <vector>
using namespace std;
int getLucky(string s, int k) {
    string cur;
    for (auto ch : s) {
        cur += to_string(ch - 'a' + 1);
    }
    int res = 0;
    while (k--){
        for (auto x : cur) {
            res += (x - '0');
        }
        cur = to_string(res);
    }
    return res;
}
int main(int argc, char const *argv[])
{
	string str = "leetcode";
	int k = 2;
	cout << getLucky(str, k) << endl;
	return 0;
}
