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

// Version 1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp1, *tmp2;
        tmp1 = l1, tmp2 = l2;

        bool flag = false;
        ListNode *ans = new ListNode;
        if (tmp1 and tmp2) {
            ans->val = (tmp1->val + tmp2->val) % 10;
            if (tmp1->val + tmp2->val >= 10) {
                flag = true;
            }

            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        ListNode *p = ans;
        ListNode *q = nullptr;
        while (tmp1 and tmp2) {
            int sum = tmp1->val + tmp2->val + flag;
            if (sum < 10) {
                flag = false;
            } else {
                flag = true;
            }

            q = new ListNode(sum % 10);
            p->next = q;
            p = q;

            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        if (!tmp1 and !tmp2) {
            if (flag) {
                q = new ListNode(1);
                p->next = q;
            }
        } else {
            ListNode *remain = (tmp1) ? tmp1 : tmp2;

            while (remain) {
                int sum = remain->val + flag;
                q = new ListNode(sum % 10);

                if (sum >= 10) {
                    flag = true;
                } else {
                    flag = false;
                }
                p->next = q;
                p = q;
                remain = remain->next;
            }

            if (flag) {
                q = new ListNode(1);
                p->next = q;
            }
        }

        return ans;
    }
};


/*Version 2:
采用头指针和尾指针来进行创建，从而避免了对第一个节点的特殊处理；
创建时先创建头指针，后续只需要 tail->next 来 new 节点即可；
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;

        bool flag = false;
        while (l1 || l2) {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;

            int sum = val1 + val2 + flag;
            if (sum >= 10) {
                flag = true;
            } else {
                flag = false;
            }

            if (!head) {
                head = new ListNode(sum % 10);
                tail = head;
            } else {
                ListNode *tmp = new ListNode(sum % 10);
                tail->next = tmp;
                tail = tail->next;
            }

            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }

        if (flag) {
            ListNode *tmp = new ListNode(1);
            tail->next = tmp;
            tail = tail->next;
        }

        return head;
    }
};
