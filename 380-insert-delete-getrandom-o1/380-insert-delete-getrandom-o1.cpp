class RandomizedSet {
public:
    set<int> s;
    int i=-1;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.count(val)>0){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)>0){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random=rand()%s.size();
        auto x=s.begin();
        for(int j=0;j<random;j++){
            x++;
        }
        return *x;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */