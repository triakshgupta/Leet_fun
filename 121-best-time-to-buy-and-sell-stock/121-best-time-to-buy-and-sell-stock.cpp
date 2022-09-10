class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0,b=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<b){
                b=prices[i];
            }
            else{
                if(prices[i]-b>p){
                    p=prices[i]-b;
                }
            }
        }
        return p;
    }
};