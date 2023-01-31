/*
 * @Author: chamip
 * @Date: 2023-01-31 17:33:40
 * @LastEditTime: 2023-01-31 22:22:51
 * @LastEditors: chamip
 * @FilePath: /undefined/Users/chamip/github/codeRecord/leetcode/123.cpp
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
		cout << "buy1 sell1 buy2 sell2" << endl;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
			cout << buy1 << " " << sell1 << " " << buy2 << " " << sell2 << endl; 
        }
        return sell2;
}

int main(int argc, char const *argv[])
{
	#ifdef BUY_SELL
	#else
		freopen("out.txt", "w", stdout);
	#endif
	vector<int> prices {3,3,5,0,0,3,1,4};
	for (const auto &x : prices) cout << x << " ";
	cout << endl;
	cout << maxProfit(prices) << endl;
	return 0;
}