class Solution {
public:
    int col(int i,int j,vector<vector<int>> grid,vector<vector<int>>& dp){
        if(i==grid.size()) return j;
        if(dp[i][j]!=-2) return dp[i][j];
        int a;
        if(grid[i][j]==1){
            if(j==grid[0].size()-1 || grid[i][j+1]==-1) a=-1;
            else a=col(i+1,j+1,grid,dp);
        }
        else{
            if(j==0 || grid[i][j-1]==1) a=-1;

            else a=col(i+1,j-1,grid,dp);
        }
        return dp[i][j]=a;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid[0].size();i++){
            dp[grid.size()][i]=i;
        }
      for(int k=0;k<grid[0].size();k++){
          for(int i=grid.size()-1;i>=0;i--){
              for(int j=k;j<grid[0].size();j++){
                  int a;
                  if(grid[i][j]==1){
                      if(j==grid[0].size()-1 || grid[i][j+1]==-1) a=-1;
                      else a=dp[i+1][j+1];
                  }
                  else{
                      if(j==0 || grid[i][j-1]==1) a=-1;

                      else a=dp[i+1][j-1];
                  }
                  dp[i][j]=a;
              }
          }
      } 
      return dp[0];
    }
};