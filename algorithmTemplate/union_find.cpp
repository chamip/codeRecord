/*
 * @Author: chamip
 * @Date: 2022-10-17 10:28:53
 * @LastEditTime: 2022-10-17 17:45:51
 * @LastEditors: chamip
 * @FilePath: /algorithmTemplate/union_find.cpp
 */

//#include <bits/stdc++.h>
//using namespace std;

struct union_find
{
    //初始化
    vector<size_t> pa;
    explicit union_find(size_t size): pa(size) {
        iota(pa.begin(), pa.end(), 0);
    }

    //查询
    size_t find(x) {
        return pa[x] == x ? x : find(pa[x]);
    }

    //合并
    void unite(size_t x, size_t y) {
        pa[find(x)] = find(y);
    }

    //启发式合并

    //删除
    
    //移动
};

