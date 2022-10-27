struct Node{
    Node* a[26];
    bool end=false;
    int pre=0;
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root=new Node();
        for(int i=0;i<words.size();i++){
            Node* temp=root;
            for(int j=0;j<words[i].size();j++){
                if(temp->a[words[i][j]-'a']==NULL){
                    Node* t=new Node();
                    temp->a[words[i][j]-'a']=t;
                    temp=t;
                    temp->pre++;
                }
                else{
                    temp=temp->a[words[i][j]-'a'];
                    temp->pre++;
                }
            }
            temp->end=true;
        }
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            Node* temp=root;
            int x=0;
            for(int j=0;j<words[i].size();j++){
                temp=temp->a[words[i][j]-'a'];
                x+=temp->pre;
            }
            ans.push_back(x);
        }
        return ans;
    }
};