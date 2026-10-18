class MyHashMap {
private:
    vector<int> hashtable;
public:
    MyHashMap() {
        hashtable.assign(1000001, -1);
    }
    
    void put(int key, int value) {
        hashtable[key] = value;
    }
    
    int get(int key) {
        return hashtable[key];
    }
    
    void remove(int key) {
        hashtable[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */