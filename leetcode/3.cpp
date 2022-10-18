/*
 * @Author: chamip
 * @Date: 2022-04-14 14:11:31
 * @LastEditTime: 2022-04-14 14:35:59
 * @LastEditors: chamip
 * @FilePath: /vscCpp/leetcode/3.cpp
 */
/*
* 输入：
* - 输入第一行包含两个正整数 n，m，表示订单的数量和小美可以接的订单数量。
* - 接下来有 n 行，第 i 行表示 i-1 号订单的信息。每行有两个正整数 v 和 w  ，表示一个订单的跑腿价格和商品重量。
* 输出：
* - 输出包含 m 个 1~n 之间的正整数，中间用空格隔开，表示选择的订单编号。
*/

#include <iostream>
#include <vector>

bool static cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int n, m;
    cin >> n >> m;
    int arr[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<pair<int, int>> pr(n);
    for (int i = 0; i < n; ++i) {
        pr[i].first = i + 1;
        pr[i].second = arr[i][0] + arr[i][1] * 2;
    }
    sort(pr.begin(), pr.end(), cmp);
    sort(pr.begin(), pr.begin() + m, [&] (auto a, auto b) {
        return a.first < b.first;
    });
    int res = 0;
    for (int i = 0; i < m; ++i) {
        cout << pr[i].first << " ";
    }
    cout << endl;
    return 0;
}