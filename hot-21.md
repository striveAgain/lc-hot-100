### 算法，时间复杂度 $O(m + n)$

经典的有序链表 / 有序数组合并问题

### C++ 代码
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *p = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                p->next = list1;
                p = p->next;

                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;

                list2 = list2->next;
            }
        }

        p->next = (list1) ? list1 : list2;

        return dummy->next;
    }
};
```
