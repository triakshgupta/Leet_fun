class Solution {
public:
    int fmin(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1000) return dp[i][j];
        int right=INT_MAX;
        int left=INT_MAX;
        if(j<matrix.size()-1){
            right=matrix[i][j]+fmin(i+1,j+1,matrix,dp);
        }
        if(j>0){
            left=matrix[i][j]+fmin(i+1,j-1,matrix,dp);
        }
        int down=matrix[i][j]+fmin(i+1,j,matrix,dp);
        //cout<<min(right,down)<<endl;
        return dp[i][j]=min(down,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1000));
        for(int i=0;i<n;i++){
            //cout<<i<<endl;
            ans=min(ans,fmin(0,i,matrix,dp));
            //cout<<ans<<endl;
        }
        return ans;
    }
};