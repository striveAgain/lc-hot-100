**可以添加一个头节点，这样不用考虑特殊情况，但注意返回时要返回 dummy->next，而不是 head，head 可能已经被删除了！！！**

### 算法一，时间复杂度 $O(n)$

先统计链表中节点的个数，然后第 len - n + 1 个节点就是要删除的节点，进行删除即可；

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *pre = head;
        while (pre) {
            ++cnt;
            pre = pre->next;
        }

        n = cnt - n;
        
        pre = nullptr;
        ListNode *cur = head;
        while (n--) {
            pre = cur;
            cur = cur->next;
        }

        if (!pre) {
            pre = head;
            head = head->next;
            delete pre;
        } else {
            pre->next = cur->next;
            delete cur;
        }

        return head;
    }
};
```

---

### 算法二，时间复杂度 $O(n)$

采用栈的思想，将所有节点入栈之后，pop 出 n 个，然后此时的栈顶就是被删除节点的前一个节点，修改指针即可；

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);

        stack<ListNode*> st;
        ListNode *cur = dummy;
        while (cur) {
            st.push(cur);
            cur = cur->next;
        }

        for (int i = 1; i <= n; ++i) {
            st.pop();
        }

        cur = st.top();
        cur->next = cur->next->next;

        return dummy->next;
    }
};
```
