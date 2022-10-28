class Solution {
public:
    int fmin(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==grid.size()-1) return grid[i][j];
        if(dp[i][j]!=-100) return dp[i][j];
        int temp=INT_MAX;
        for(int x=0;x<grid.size();x++){
            if(x!=j) temp=min(grid[i][j]+fmin(i+1,x,grid,dp),temp);
        }
        return dp[i][j]=temp;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-100));
        for(int i=0;i<grid.size();i++){
            ans=min(ans,fmin(0,i,grid,dp));
        }
        return ans;
    }
};