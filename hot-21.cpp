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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *tail;
        head = tail = nullptr;

        while (list1 and list2) {
            ListNode *tmp = (list1->val < list2->val) ? list1 : list2;

            if (!head) {
                head = new ListNode(tmp->val);
                tail = head;
            } else {
                tail->next = new ListNode(tmp->val);
                tail = tail->next;
            }

            if (tmp == list1) {
                list1 = list1->next;
            } else {
                list2 = list2->next;
            }
        }

        ListNode *remain = (list1) ? list1 : list2;
        while (remain) {
            if (!head) {
                head = new ListNode(remain->val);
                tail = head;
            } else {
                tail->next = new ListNode(remain->val);
                tail = tail->next;
            }
            remain = remain->next;
        }

        return head;
    }
};

// Version 2
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *tail;
        head = tail = new ListNode(-1);

        while (list1 and list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                tail = tail->next;

                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = tail->next;

                list2 = list2->next;
            }
        }

        tail->next = (list1) ? list1 : list2;

        return head->next;
    }
};
