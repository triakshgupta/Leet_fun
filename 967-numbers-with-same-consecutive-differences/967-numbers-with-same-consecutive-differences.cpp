class Solution {
public:
    void solve(vector<int>& ans,string s,int n,int k){
        if(s.size()==n){
            ans.push_back(stoi(s));
            return;
        }
        if(((s[s.size()-1])-'0')-k>=0){
            solve(ans,s+to_string(((s[s.size()-1])-'0')-k),n,k);
        }
        if(((s[s.size()-1])-'0')+k<10 && ((s[s.size()-1])-'0')-k!=((s[s.size()-1])-'0')+k){
            solve(ans,s+to_string(((s[s.size()-1])-'0')+k),n,k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            string s=to_string(i);
            solve(ans,s,n,k);
        }
        return ans;
    }
};