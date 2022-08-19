class Solution {
public:
    void solve(vector<string>& ans,string s,int ind,string digits,map<char,string> mp){
        if(ind==digits.length()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<mp[digits[ind]].length();i++){
            solve(ans,s+mp[digits[ind]][i],ind+1,digits,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        solve(ans,"",0,digits,mp);
        return ans;
    }
};