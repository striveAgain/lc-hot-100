### 算法一，时间复杂度 $O(k \times n)$
**`k` 为链表个数，`n` 为每个链表的最大长度；**

采用类似于合并两个有序链表的方式，每次比较所有的当前链表头，找到最小的节点；

然后采用尾插法进行插入即可；

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
    bool check(vector<ListNode*>& lists) {
        int n = lists.size();
        for (int i = 0; i < n; ++i) {
            if (lists[i]) {
                return true;
            }
        }

        return false;
    }
 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) {
            return nullptr;
        }

        if (n == 1) {
            return lists[0];
        }

        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while (check(lists)) {
            ListNode *p = nullptr;
            int idx = -1;

            for (int i = 0; i < n; ++i) {
                if (lists[i] && (!p || lists[i]->val < p->val)) {
                    p = lists[i];
                    idx = i;
                }
            }

            tail->next = p;
            tail = tail->next;

            lists[idx] = lists[idx]->next;
        }

        return dummy->next;
    }
};
```

---

### 算法二，时间复杂度 $kn \times \log k$

采用堆来维护 `k` 个链表中的 `k` 个数的最小值，每次 `pop()` 出节点之后采用尾插法插入到新的链表中即可；

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
    struct node {
        int val;
        ListNode* p;

        bool operator<(const node& q) const {
            return val > q.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        priority_queue<node> pq;
        for (int i = 0; i < n; ++i) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while (!pq.empty()) {
            node cur = pq.top();
            pq.pop();

            tail->next = cur.p;
            tail = tail->next;

            if (tail->next) {
                pq.push({tail->next->val, tail->next});
            }
        }

        return dummy->next;
    }
};
```
