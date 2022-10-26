struct Node{
    Node* a[26];
    bool end=false;
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->a[word[i]-'a']==NULL){
                //cout<<word[i]-'a'<<endl;
                Node* t=new Node();
                temp->a[word[i]-'a']=t;
                temp=t;
            }
            else temp=temp->a[word[i]-'a'];
        }
        temp->end=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->a[word[i]-'a']==NULL){
                return false;
            }
            else temp=temp->a[word[i]-'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++){
            if(temp->a[prefix[i]-'a']==NULL){
                return false;
            }
            else temp=temp->a[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */