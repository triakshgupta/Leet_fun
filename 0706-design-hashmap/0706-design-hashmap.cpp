class MyHashMap {
public:
    vector<int> m;
    MyHashMap() {
        vector<int> x(1000001,-1);
        m=x;
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */