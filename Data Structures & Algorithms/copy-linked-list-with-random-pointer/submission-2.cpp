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
        if (!head) return nullptr;

        unordered_map<Node*, Node*> oldTocopy;
        oldTocopy[nullptr] = nullptr;

        Node* cur = head;
        while (cur) {
            oldTocopy[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            oldTocopy[cur]->next = oldTocopy[cur->next];
            oldTocopy[cur]->random = oldTocopy[cur->random];
            cur = cur->next;
        }
        return oldTocopy[head];
    }
};
