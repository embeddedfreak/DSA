class LRUCache {
public:

    void addNode(Node* newNode)
    {
        Node* oldNode = head->next;
        head->next = newNode;
        newNode->next = oldNode;
        newNode->prev = head;
        oldNode->prev = newNode;
    }

    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v)
        {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    unordered_map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {

        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {

        Node* newNode = new Node(key, val);
        addNode(newNode);
        mp[key] = newNode;   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
