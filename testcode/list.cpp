//合并两个有序连表

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() {val = 0; next = nullptr;};
    ListNode(int v): val(v), next(nullptr) {};
};

ListNode* solve(ListNode *head1, ListNode *head2) {
    ListNode *pre = new ListNode();
    ListNode *cur = pre;
    ListNode *cur1 = head1, *cur2 = head2;
    while (cur1 || cur2) {
        if (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
                cur = cur->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
                cur = cur->next;
            }
        } else if (cur1) {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        } else if (cur2) {
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
    }
    return pre->next;
}

int main()
{
    std::vector<int> vec1 = {1, 3, 5};
    std::vector<int> vec2 = {2, 4, 6};
    ListNode *head1 = new ListNode(), *head2 = new ListNode();
    ListNode *cur1 = head1, *cur2 = head2;
    for (int i = 0; i < 3; ++i) {
        cur1->next = new ListNode(vec1[i]);
        cur1 = cur1->next;
    }
    for (int i = 0; i < 3; ++i) {
        cur2->next = new ListNode(vec2[i]);
        cur2 = cur2->next;
    }
    ListNode *ans = solve(head1->next, head2->next);
    while (ans) {
        std::cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}