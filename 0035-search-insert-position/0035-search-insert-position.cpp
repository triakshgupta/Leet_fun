class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=nums.size();
        int i=0;
        int j=nums.size()-1;
        int mid=j+(i-j)/2;
        while(i<=j){
            mid=j+(i-j)/2;
            // if(nums[mid]==target) return mid;
            if(nums[mid]>=target){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        // if(ans==INT_MAX) return nums.size();
        // if(ans==-1) return 0;
        return ans;
    }
};