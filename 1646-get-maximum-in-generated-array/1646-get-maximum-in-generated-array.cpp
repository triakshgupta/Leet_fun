class Solution {
public:
    int temp(int n,vector<int>& dp){
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        if(n%2!=0){
            return dp[n]=temp((n-1)/2,dp) +temp((n+1)/2,dp);
        }
        else{
            return dp[n]=temp(n/2,dp);
        }
    }
    int getMaximumGenerated(int n) {
        int ans=0;
        vector<int> dp(n+1,-1);
        for(int i=1;i<=n;i++){
            ans=max(ans,temp(i,dp));
        }
        return ans;
    }
};