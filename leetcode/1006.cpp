#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        int res = 0;
        int flag = 1;
        while (n >= 4) {
            res += flag * (n * (n - 1) / (n - 2) + (n - 3));
            if (flag == 1) flag = -1;
            n -= 4;
        }
        if (n == 3) {
            res += flag * (n * (n - 1) / (n - 2));
        }
        if (n == 2) {
            res += flag * (n * (n - 1));
        }
        if (n == 1) {
            res += flag * n;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution *s = new Solution();
    int n;
    cin >> n;
    cout << s->clumsy(n) << endl; 
	return 0;
}
