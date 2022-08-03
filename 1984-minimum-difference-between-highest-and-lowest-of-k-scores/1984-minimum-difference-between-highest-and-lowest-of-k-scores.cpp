class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=1,j=k;
        int ans=nums[k-1]-nums[0];
        while(j<nums.size()){
            ans=min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};