class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=e+(s-e)/2;
            if((mid==nums.size()-1 && nums[mid]<target) || (nums[mid]<target && nums[mid+1]>target)){
                return mid+1;
            }
            else if(nums[mid]==target || (mid==0 && nums[mid]>target)){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return 0;
    }
};