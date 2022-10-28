class Solution {
public:
    int sum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[grid.size()-1][grid[0].size()-1];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right=INT_MAX;
        int down=INT_MAX;
        if(i<grid.size()-1){
            down=grid[i][j]+sum(i+1,j,grid,dp);
        }
        if(j<grid[0].size()-1){
            right=grid[i][j]+sum(i,j+1,grid,dp);
        }
        return dp[i][j]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return sum(0,0,grid,dp);
    }
};