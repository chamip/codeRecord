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
    const int MOD = 1e9 + 7;
    bool check(int k) {
        if (k == 1) return false;
        for (int t = 2; t * t <= k; ++t) {
            if (k % t == 0) return false;
        }
        return true;
    }
    long long getAns(int cnt) {
        if (cnt == 0) return 0;
        long long ans = 1;
        while (cnt) ans = (ans * cnt--) % MOD;
        return ans;
    }
    int numPrimeArrangements(int n) {
        long long res = 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (check(i)) ++cnt;
        }
        res = (res * getAns(cnt)) % MOD;
        res = (res * getAns(n - cnt)) % MOD; 
        return (int)res;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fileIO();
    int n;
    cin >> n; 
    Solution *s = new Solution();
    int res = s->numPrimeArrangements(n);
    cout << res << endl;
	return 0;
}
