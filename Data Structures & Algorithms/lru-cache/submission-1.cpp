class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        // Insert just before tail = most recently used
        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // It was just used, so make it MRU
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Make it most recently used
            remove(node);
            insert(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {

            // First real node = LRU
            Node* lru = head->next;

            mp.erase(lru->key);
            remove(lru);

            delete lru;
        }

        // Add new node as MRU
        Node* node = new Node(key, value);

        mp[key] = node;
        insert(node);
    }
};