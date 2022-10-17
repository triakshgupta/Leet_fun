class Solution {
public:
    void solve(vector<int>& temp,vector<vector<int>>& ans,int i,int n,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(i>n){
            return;
        }
        solve(temp,ans,i+1,n,k);
        temp.push_back(i);
        solve(temp,ans,i+1,n,k);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(temp,ans,1,n,k);
        return ans;
    }
};