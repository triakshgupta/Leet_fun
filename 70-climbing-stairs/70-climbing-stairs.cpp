class Solution {
public:
    
    // Memoization
    // int countmove(int i,vector<int>& dp){
    //     if(i<=1){
    //         return 1;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     int one=countmove(i-1,dp);
    //     int two=0;
    //     if(i>1){
    //         two=countmove(i-2,dp);
    //     }
    //     return dp[i]=one+two;
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return countmove(n,dp);
    // }
    
    
    //  Tabulation
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(i>=2) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};