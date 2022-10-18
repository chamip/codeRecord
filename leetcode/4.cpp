/*
 * @Author: chamip
 * @Date: 2022-04-14 16:37:45
 * @LastEditTime: 2022-04-14 17:14:43
 * @LastEditors: chamip
 * @FilePath: /vscCpp/leetcode/4.cpp
 */
/*
* 小团是一个莫得感情的 CtrlCV 大师，他有一个下标从 1 开始的序列 A 和一个初始全部为 -1 序列 B ，两个序列的长度都是 n 。
* 他会进行若干次操作，每一次操作，他都会选择 A 序列中一段连续区间，将其粘贴到 B 序列中的某一个连续的位置，在
* 这个过程中他也会查询 B 序列中某一个位置上的值。
* 我们用如下的方式表示他的粘贴操作和查询操作：
* 粘贴操作：1 k x y，表示把 A 序列中从下标 x 位置开始的连续 k 个元素粘贴到 B 序列中从下标 y 开始的连续 k 个位置上。
* 原始序列中的元素被覆盖。（注意：输入数据可能会出现粘贴后 k 个元素超出 B 序列原有长度的情况，超出部分可忽略）
* 查询操作：2 x，表示询问B序列下标 x 处的值是多少。
*   输入：
* - 输入第一行包含一个正整数 n ，表示序列 A 和序列 B 的长度。
* - 输入第二行包含 n 个正整数，表示序列 A 中的 n 个元素，第 i 个数字表示下标为 i 的位置上的元素，每一个元素保证在 10^9 以内。
* - 输入第三行是一个操作数 m ，表示进行的操作数量。
* - 接下来 m 行，每行第一个数字为 1 或 2 ，具体操作细节详见题面。
* 输出：
* - 对于每一个操作 2 输出一行，每行仅包含一个正整数，表示针对某一个询问的答案。
*/
#include <iostream>
#include <vector>

int main(int argc, char const* argv[])
{
    using namespace std;
    int n;
    cin >> n;
    vector<int> A(n + 1, 0);
    vector<int> B(n + 1, -1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> A[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        if (q == 1) {
            int k, x, y;
            cin >> k >> x >> y;
            int miny = min(y + k - 1, n);
            for (int i = x, j = y; j <= miny; ++i, ++j) {
                B[j] = A[i];
            }
        } else if (q == 2) {
            int x;
            cin >> x;
            cout << B[x] << endl;
        }
    }
    return 0;
}