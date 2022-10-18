#include <iostream>
#include <vector>
using namespace std;
vector<string> divideString(string s, int k, char fill) {
    int len = s.size();
    int i = 0;
    vector<string> res;
    while (i < len) {
        if (i + k <= len) {
            res.emplace_back(s.substr(i, i + k));
            i += k;
        } else {
            string temp = s.substr(i, len - i);
            int t = k - temp.size();
            while (t--) {
                temp += fill;
            }
            res.emplace_back(temp);
            i = len;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
	string s = "abcdefghi";
	int k = 3;
	char fill = 'x';
	vector<string> v = divideString(s, k, fill);
	return 0;
}
