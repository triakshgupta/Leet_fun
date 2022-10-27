struct Node{
    Node* a[26];
    bool end=false;
    int sum=0;
};
class MapSum {
public:
    map<string,int> m;
    Node* root;
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        if(m.count(key)==0){
            Node* temp=root;
            for(int i=0;i<key.size();i++){
                if(temp->a[key[i]-'a']==NULL){
                    Node* t=new Node();
                    temp->a[key[i]-'a']=t;
                    temp=t;
                    temp->sum+=val;
                }
                else{
                    temp=temp->a[key[i]-'a'];
                    temp->sum+=val;
                }
            }
            temp->end=true;
            //temp->sum+=val;
            m[key]=val;
        }
        else{
            Node* temp=root;
            for(int i=0;i<key.size();i++){
                temp=temp->a[key[i]-'a'];
                temp->sum+=val-m[key];
            }
            //temp->sum+=val-m[key];
            m[key]=val;
        }
    }
    
    int sum(string prefix) {
            Node* temp=root;
            for(int i=0;i<prefix.size();i++){
                if(temp->a[prefix[i]-'a']==NULL){
                    return 0;
                }
                else{
                    temp=temp->a[prefix[i]-'a'];
                }
            }
        return temp->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */