/*
 * @Author: chamip
 * @Date: 2022-08-05 16:10:45
 * @LastEditTime: 2022-08-05 17:19:45
 * @LastEditors: chamip
 * @FilePath: /leetcode/LM.cpp
 */
/*
 * @Author: chamip
 * @Date: 2022-08-05 16:07:51
 * @LastEditTime: 2022-08-05 16:09:22
 * @LastEditors: chamip
 * @FilePath: /newcoder/LM.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const * argv[])
{
    int L, M;
    cin >> L >> M;
    vector<vector<int>> arr(M, vector<int>(2));
    for (int i = 0; i < M; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end(), [] (const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });
    int cur = 0;
    int left = arr[0][0];
    int right = arr[0][1];
    for (int i = 1; i < M;) {
        while (right >= arr[i][0] && i <M) {
            right = arr[i][1];
            ++i;
        }
        cur += (right - left) + 1;
        ++i;
        left = arr[i][0];
        right = arr[i][1];
    }
    cout << L + 1 - cur << endl;
    return 0;
}