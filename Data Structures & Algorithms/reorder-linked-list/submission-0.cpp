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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = NULL;
        slow->next = NULL;

        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }
        second = prev;

        ListNode dummy(0);
        ListNode* tmp = &dummy;
        while(head && second) {
            tmp->next = head;
            tmp = tmp->next;
            head = head->next;
            tmp->next = second;
            tmp = tmp->next;
            second = second->next;
        }
        if (head) {
            tmp->next = head;
        } else {
            tmp->next = second;
        }
        head = dummy.next;
    }
};
