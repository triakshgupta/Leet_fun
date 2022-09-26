class Solution {
public:
    // Memoization
    // int solve(int x,vector<int>& dp){
    //     if(x<=1){
    //         return x;
    //     }
    //     if(dp[x]!=-1){
    //         return dp[x];
    //     }
    //     return dp[x]=solve(x-1,dp)+solve(x-2,dp);
    // }
    // int fib(int n) {
    //     vector<int> dp(n+1,-1);
    //     return solve(n,dp);
    // }
    
    
    
    int fib(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        if(n>=1) dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};