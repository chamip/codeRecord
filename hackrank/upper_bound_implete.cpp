/*
 * @Author: chamip
 * @Date: 2022-04-13 10:18:21
 * @LastEditTime: 2022-04-13 10:20:26
 * @LastEditors: chamip
 * @FilePath: /vscCpp/hackrank/upper_bound_implete.cpp
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void check(const vector<int>& vec, int x) {
    // using namespace boost::typeindex;
    // auto it = lower_bound(vec.begin(),vec.end(), x);
    // cout << type_id_with_cvr<decltype(it)>().pretty_name() << endl;
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int idx = left;
    if (idx >= vec.size()) {
        cout << "No " << idx + 1 << endl;
    } else if (vec[idx] == x) {
        cout << "Yes " << (idx + 1) << endl;
    } else {
        cout << "No " << (idx + 1) << endl;
    }
    return ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int q, x;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> x;
        check(vec, x);
    }
    return 0;
}
