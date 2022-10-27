struct Node{
    Node* a[26];
    bool end=false;
};
class Solution {
public:
    void solve(vector<string>& ans1,int& count,Node* t,string temp){
        if(t->end){
            ans1.push_back(temp);
            count--;
        }
        if(count==0) return;
        for(int i=0;i<26;i++){
            if(t->a[i] && count!=0){
                solve(ans1,count,t->a[i],temp+char(i+97));
            }
        }
        return;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        vector<vector<string>> ans;
        Node* root=new Node();
        for(int i=0;i<products.size();i++){
            Node* temp=root;
            for(int j=0;j<products[i].size();j++){
                if(temp->a[products[i][j]-'a']==NULL){
                    Node* t=new Node();
                    temp->a[products[i][j]-'a']=t;
                    temp=t;
                }
                else temp=temp->a[products[i][j]-'a'];
            }
            temp->end=true;
        }
        string s="";
        for(int i=0;i<search.size();i++){
            s+=search[i];
            vector<string> ans1;
            Node* temp=root;
            int f=0;
            for(int j=0;j<s.size();j++){
                if(temp->a[s[j]-'a']==NULL){
                    f=1;
                    break;
                }
                else{
                    temp=temp->a[s[j]-'a'];
                }
            }
            int c=3;
            if(f==0) solve(ans1,c,temp,s);
            ans.push_back(ans1);
        }
        return ans;
    }
};