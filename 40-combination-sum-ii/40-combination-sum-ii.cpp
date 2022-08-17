class Solution {
public:
    void sum(vector<vector<int>>& ans,vector<int>& path,int t,int s,vector<int> cand,int i){
        if(s==t)
        {
            ans.push_back(path);
            return;
        }
        if(s>t){
            return;
        }
        for(int j=i+1;j<cand.size();j++){
            if(j==i+1 || cand[j]!=cand[j-1]){
            path.push_back(cand[j]);
            sum(ans,path,t,s+cand[j],cand,j);
            path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<int> path;
        vector<vector<int>> ans;
        sum(ans,path,target,0,cand,-1);
        return ans;
    }
};