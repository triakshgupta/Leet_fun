class Solution {
public:
    int count(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int down=0;
        if(i<m-1){
            down=count(i+1,j,m,n,dp);
        }
        if(j<n-1){
            left=count(i,j+1,m,n,dp);
        }
        return dp[i][j]=left+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return count(0,0,m,n,dp);
    }
};