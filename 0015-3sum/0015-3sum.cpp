class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            if(i==0 || nums[i]!=nums[i-1]){
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> t={nums[i],nums[j],nums[k]};
                    ans.push_back(t);
                    while(j<k && nums[k-1]==nums[k]) k--;
                    while(j<k && nums[j+1]==nums[j]) j++;
                    k--;
                    j++;
                }
                else if(sum<0) j++;
                else k--;
            }
            }
        }
        return ans;
    }
};