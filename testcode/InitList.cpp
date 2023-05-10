/*
 * 初始化列表时，元素的初始化顺序与其声明的顺序一致，而与初始化列表中元素的顺序无关 
 */

class X {
private:
    int i;
    int j;
public:
    // 报错，i先初始化为j，但是j未定义
    // X(int val): j(val), i(j) {}
    X(int val): i(val), j(val) {}
};