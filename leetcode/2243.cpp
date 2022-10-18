#include <iostream>
#include <vector>
using namespace std;
string digitSum(string s, int k) {
    int len = s.size();
    string cur;
    while (len > k) {
        int i = 0;
        string temp;
        while (i < len) {
            if (i + k <= len) {
                temp = s.substr(i, i + k);
                i += k;
            } else {
                temp = s.substr(i, len - i);
                i = len;
            }
            int res = 0;
            for (auto x : temp) {
                res += (x - '0');
            }
            temp = to_string(res);
            cur += temp;
        }
        s = cur;
        len = s.size();
        cur.clear();
    }
    return s;    
}
int main(int argc, char const *argv[])
{
	string s = "11111222223";
	int k = 3;
	cout << digitSum(s, k) << endl;
	return 0;
}
