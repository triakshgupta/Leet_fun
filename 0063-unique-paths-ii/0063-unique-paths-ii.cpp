class Solution {
public:
    int count(vector<vector<int>>& o,int i,int j,vector<vector<int>>& dp){
        if(i==o.size()-1 && j==o[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int down=0;
        if(j<o[0].size()-1 && o[i][j+1]!=1){
            left=count(o,i,j+1,dp);
        }
        if(i<o.size()-1 && o[i+1][j]!=1){
            down=count(o,i+1,j,dp);
        }
        return dp[i][j]=left+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]) return 0;
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return count(obstacleGrid,0,0,dp);
    }
};