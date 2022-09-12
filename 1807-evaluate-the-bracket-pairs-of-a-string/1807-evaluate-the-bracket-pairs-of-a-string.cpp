class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> k;
        for(int i=0;i<knowledge.size();i++){
            k[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                if(k.count(temp)>0){
                    ans+=k[temp];
                }
                else{
                    ans.push_back('?');
                }
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};