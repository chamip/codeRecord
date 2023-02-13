#include <iostream>
#include <vector>
using namespace std;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        string temp = "";
        for (char ch : s) {
            if (ch != '-') {
                ++cnt;
                temp += toupper(ch);
            }
        }
        //cout << "cnt: " << cnt << endl;
        int remainder = cnt % k;
        //cout << "remainder: " << remainder << endl;
        string res = "";
        for (int i = 0; i < cnt;) {
            int cur = 0;
            if (i == 0) {
                if (remainder != 0) {
                    while (i < cnt && cur < remainder) {
                        res += temp[i++];
                        ++cur;
                    }
                } else {
                    while (i < cnt && cur < k) {
                        res += temp[i++];
                        ++cur;
                    }
                }
            } else {
                res += '-';
                while (i < cnt && cur < k) {
                    res += temp[i++];
                    ++cur;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fileIO();
    Solution *s = new Solution();
    std::string str;
    int k;
    std::cin >> str >> k;
    std::string res = s->licenseKeyFormatting(str, k);
    std::cout << res << std::endl;
    
	return 0;
}
