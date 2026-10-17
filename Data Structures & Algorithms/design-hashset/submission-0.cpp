class MyHashSet {
private:
    static const int BASE = 769;
    vector<list<int>> buckets;
    int hash(int key){
        return key % BASE;
    }
public:
    MyHashSet() {
        buckets.resize(BASE);
    }
    
    void add(int key) {
        int idx = hash(key);
        for (int element : buckets[idx]){
            if (element == key){
                return;   
            }
        }
        buckets[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        if (it != buckets[idx].end()){
            buckets[idx].erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for (int element : buckets[idx]){
            if (element == key){
                return 1;
            }
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */