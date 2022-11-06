struct Node{
    Node* a[26];
    bool end=false;
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Node* root=new Node();
        for(int i=0;i<strs.size();i++){
            Node* temp=root;
            if(strs[i]=="") return "";
            for(int j=0;j<strs[i].size();j++){
                if(temp->a[strs[i][j]-'a']==NULL){
                    Node* t=new Node();
                    temp->a[strs[i][j]-'a']=t;
                    temp=t;
                }
                else temp=temp->a[strs[i][j]-'a'];
            }
            temp->end=true;
        }
        Node* temp=root;
        string s,ans;
        while(1){
            Node* t=NULL;
            for(int i=0;i<26;i++){
                if(temp->a[i]!=NULL && t!=NULL) return ans;
                else if(temp->a[i]!=NULL) {
                    t=temp->a[i];
                    s.push_back('a'+i);
                    cout<<s<<endl;
                }
            }
            if(t->end==true) return s;
            temp=t;
            ans=s;
        }
        return "";
    }
};