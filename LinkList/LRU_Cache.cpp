class LRUCache {
public:
    // Doubly Linked List node structure
    class Node {
    public:
        int key;        // Cache key
        int val;        // Cache value
        Node* next;     // Pointer to next node
        Node* prev;     // Pointer to previous node

        // Constructor to initialize node
        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    // Dummy head and tail nodes to simplify insertion and deletion
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Hash map to store key → node address mapping
    unordered_map<int, Node*> mp;

    // Maximum capacity of the cache
    int limit;

    // Step 1: Add a node just after the head (most recently used position)
    void addNode(Node* newNode) {
        Node* oldNode;
        oldNode = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNode;
        oldNode->prev = newNode;
    }

    // Step 2: Remove a node from the doubly linked list
    void deleteNode(Node* oldNode) {
        Node* oldNode_prev = oldNode->prev;
        Node* oldNode_next = oldNode->next;

        oldNode_prev->next = oldNode_next;
        oldNode_next->prev = oldNode_prev;
    }

    // Step 3: Initialize the cache with given capacity
    // and connect dummy head and tail nodes
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Step 4: Get the value associated with a key
    int get(int key) {
        // If key does not exist, return -1
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Retrieve value from the node
        int ans = mp[key]->val;

        // Move accessed node to front (most recently used)
        deleteNode(mp[key]);
        addNode(mp[key]);

        return ans;
    }

    // Step 5: Insert or update a key-value pair
    void put(int key, int value) {

        // If key already exists, remove its old node
        if (mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
            mp.erase(key);
        }

        // If cache is full, remove least recently used node
        if (mp.size() == limit) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // Step 6: Create a new node and insert it at the front
        Node* newNode = new Node(key, value);
        addNode(newNode);

        // Step 7: Store new key-node mapping in hash map
        mp[key] = newNode;
    }
};
