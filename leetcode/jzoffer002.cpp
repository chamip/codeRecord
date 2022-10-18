#include <iostream>
#include <vector>
using namespace std;
string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len1 = a.size();
    int len2 = b.size();
    int carry = 0;
    string res;
    int i = 0;
    int j = 0;
    while (i < len1 || j < len2) {
        int x = 0;
        int y = 0;
        if (i < len1) {
            x = a[i] - '0';
        }
        if (j < len2) {
            y = b[j] - '0';
        }
        res += to_string((x + y + carry) % 2);
        if (x + y + carry > 1) {
            carry = 1;
        }
        ++i;
        ++j;
    }
    if (carry == 1) {
        res += to_string(1);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, char const *argv[])
{
	string a = "1010";
	string b = "1011";
	cout << addBinary(a, b) << endl;
	return 0;
}
