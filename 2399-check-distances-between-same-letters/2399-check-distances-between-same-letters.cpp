class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])==0){
                m[s[i]]=i;
            }
            else{
                if(i-m[s[i]]-1!=distance[s[i]-'a']) return false;
            }
        }
        return true;
    }
};