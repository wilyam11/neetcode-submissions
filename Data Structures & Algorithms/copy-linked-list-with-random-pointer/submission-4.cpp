/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // O(1) mem interleave
        if (head == nullptr) {
            return nullptr;
        }
        // A->A'
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            copy->random = cur->random;
            cur->next = copy;
            cur = copy->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node* newlist = head->next;
        cur = head;
        while (cur) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            if(tmp->next) {
                tmp->next = tmp->next->next;
            }
            cur = cur->next;
        }
        return newlist;
    }
};
