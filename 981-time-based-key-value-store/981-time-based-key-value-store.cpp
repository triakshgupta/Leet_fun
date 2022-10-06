class TimeMap {
public:
    map<string,map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
        // for(auto i:m[key]){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
    }
    
    string get(string key, int timestamp) {
        if(m.count(key)==0){
            return "";
        }
        else{
            for(int i=timestamp;i>=1;i--){
                if(m[key].count(i)>0){
                    return m[key][i];
                }
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */