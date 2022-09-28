class Solution {
public:
    // int sumcost(int i,vector<int> cost,vector<int>& dp){
    //     if(i<0){
    //         return 0;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     int one=cost[i]+sumcost(i-1,cost,dp);
    //     int two=cost[i]+sumcost(i-2,cost,dp);
    //     return dp[i]=min(one,two);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            int one=cost[i]+dp[i-1];
            int two=cost[i]+dp[i-2];
            dp[i]=min(one,two);
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};