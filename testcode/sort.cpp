/*
题目1：
struct n_t {
    int a;
    int b;
};
int sort(n_t* p, int len);

实现sort函数，该函数输入已经按照字段a排序的数组p，数组p长度为len，使相邻的n_t之间b不相等，但尽量保持p原来顺序，交换调整次数尽量少。返回值为执行状态标识。
比如输入元素为：
	1. 
{2，3}
	2. 
{3，4}
	3. 
{5，4}
	4. 
{10，7}


如上四个元素，其中2，3的b都是4，所以可以把第3，4进行交换，得到：
	1. 
{2，3}
	2. 
{3，4}
	3. 
{10，7}
	4. 
{5，4}
*/
#include <iostream>

struct n_t {
    int a;
    int b;
};

int mysort(n_t *b, int len) {

}

int main()
{

    return 0;
}