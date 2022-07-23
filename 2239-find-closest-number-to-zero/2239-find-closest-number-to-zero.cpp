class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<abs(min) || (abs(nums[i])==abs(min) && nums[i]>min)){
                min=nums[i];
            }
        }
        return min;
    }
};