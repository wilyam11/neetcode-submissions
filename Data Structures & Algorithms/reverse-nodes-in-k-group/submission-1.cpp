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
private:
    int countLen(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        if (k == 1) return head;
        int t = countLen(head) / k;

        ListNode dummy(0);
        ListNode* prevtail = &dummy;
        ListNode* grouphead = nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        for (int i = 0; i < t; i++) {
            grouphead = cur;
            for (int j = 0; j < k; j++) {
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            } 
            prevtail->next = prev;
            prevtail = grouphead;
            prev = nullptr;
        }
        prevtail->next = cur;

        return dummy.next; 
    }
};
