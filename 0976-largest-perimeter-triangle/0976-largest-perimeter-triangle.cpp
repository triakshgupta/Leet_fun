class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int s=nums.size();
        sort(nums.begin(),nums.end());
        int one=s-1,two=s-2,three=s-3;
        int ans=INT_MIN;
        while(three>=0){
            if(nums[one]+nums[two]>nums[three] && nums[two]+nums[three]>nums[one] && nums[one]+nums[three]>nums[two]){
                ans=max(ans,nums[one]+nums[two]+nums[three]);
                break;
            }
            one=two;
            two=three;
            three--;
        }
        return ans==INT_MIN? 0:ans;
    }
};