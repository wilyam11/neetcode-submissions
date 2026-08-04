struct Node {
    int key;
    int val;
    Node* prev{nullptr};
    Node* next{nullptr};

    Node(int k, int v): key(k), val(v) {}
};

class LRUCache {
private:
    int cap;
    std::unordered_map<int, Node*> hashmap;
    Node* left;
    Node* right;
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    void insert(Node* node) {   // insert node to right of list
        Node* prev = right->prev;
        node->prev = prev;
        prev->next = node;
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (hashmap.find(key) != hashmap.end()) {
            Node* node = hashmap[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (hashmap.find(key) != hashmap.end()) {
            Node* node = hashmap[key];
            remove(node);
            insert(node);
            node->val = value;
            return;
        }
        Node* node = new Node(key, value);
        insert(node);
        hashmap[key] = node;
        if (hashmap.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            hashmap.erase(lru->key);
        }
        return;
    }
};
