class Solution {
public:
    // if(i>=cost.size()){
    //         return c;
    //     }
    //     int one=sumcost(i+1,c+cost[i],cost);
    //     int two=INT_MAX;
    //     if(i<=cost.size()-3){
    //         two=sumcost(i+2,c+cost[i],cost);
    //     }
    //     return min(one,two);
    
    int sumcost(int i,vector<int> cost,vector<int>& dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=cost[i]+sumcost(i-1,cost,dp);
        int two=cost[i]+sumcost(i-2,cost,dp);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(sumcost(cost.size()-1,cost,dp),sumcost(cost.size()-2,cost,dp));
    }
};