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
    ListNode* merge(ListNode* & l1, ListNode* & l2) {
        ListNode dummy(0);
        ListNode* tmp = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1) {
            tmp->next = l1;
        } else {
            tmp->next = l2;
        }
        return dummy.next;
    }
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (lists.empty()) return nullptr;
        if (l > r) return nullptr;
        if (l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid+1, r);
        return merge(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        return divide(lists, 0, lists.size()-1);
    }
};
