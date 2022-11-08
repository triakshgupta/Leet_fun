class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long ans=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==target) return target;
                else{
                    if(abs(nums[i]+nums[j]+nums[k]-target)<abs(ans-target)) ans=nums[i]+nums[k]+nums[j];
                    if(nums[i]+nums[j]+nums[k]<target) j++;
                    else k--;
                }
            }
        }
        return ans;
    }
};