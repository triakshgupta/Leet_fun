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
        for(int j=i;j<cand.size();j++){
            path.push_back(cand[j]);
            sum(ans,path,t,s+cand[j],cand,j);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sum(ans,path,target,0,cand,0);
        return ans;
    }
};