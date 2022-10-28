class Solution {
public:
    int minsum(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ind=triangle[i][j]+minsum(i+1,j,triangle,dp);
        int indn=triangle[i][j]+minsum(i+1,j+1,triangle,dp);
        return dp[i][j]=min(ind,indn);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return minsum(0,0,triangle,dp);
    }
};