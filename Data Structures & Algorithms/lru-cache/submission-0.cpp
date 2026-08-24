class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node (int k , int v) : key(k) , val(v) , prev(nullptr) , next(nullptr){}
    };
    int capacity;
    unordered_map<int , Node*> cache;
    Node* head;
    Node* tail;


public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node (-1 , -1);
        tail = new Node (-1 , -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key) == 0){return -1;}
        Node* node = cache[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key) != 0){
            Node* node = cache[key];
            node->val = value;

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
        else{
            if(cache.size() == capacity){
                Node* lru = tail->prev;
                cache.erase(lru->key);
                lru->prev->next = lru->next;
                lru->next->prev = lru->prev;
                delete lru;
            }
            Node* node = new Node( key , value);
            cache[key] = node;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    }
};
