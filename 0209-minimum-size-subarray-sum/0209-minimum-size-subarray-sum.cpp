class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0,ans=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<target) j++;
            else{
                ans=min(ans,j-i+1);
                while(sum>target && i<j){
                    sum-=nums[i];
                    i++;
                    if(sum>=target){
                       ans=min(ans,j-i+1);
                    }
                }
                j++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};