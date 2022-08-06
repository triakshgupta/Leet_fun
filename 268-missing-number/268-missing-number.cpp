class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return nums.size();
    }
};