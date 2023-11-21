// 1，2，3，4， 5
//      6 7 8 9
//        10 11

#include <list>
struct ListNode {
    int _val;
    ListNode* _pre;
    ListNode* _next;
    ListNode* _extra;
    ListNode(): _val(0), _pre(nullptr), _next(nullptr), _extra(nullptr) {}
};

ListNode* solve(ListNode* node) {
    ListNode* pre = new ListNode();
    pre->_next = node;
    ListNode* cur = node;
    ListNode* next;
    while (cur) {
        if (cur->_extra) {
            next = cur->_next;
            ListNode *start = cur->_extra;
            ListNode *end = cur->_extra;
            while (end->_next) {
                end = end->_next;
            }
            cur->_next = solve(start);
            cur->_extra = nullptr;
            start->_pre = cur;
            end->_next = next;
            next->_pre = end;
        }
        cur = cur->_next;
    }
    return pre->_next;
}

int main()
{
    ListNode* root = solve() 

}