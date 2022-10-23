class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> t(nums.size()+1,1);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(t[nums[i]]){
                t[nums[i]]=0;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(t[i]){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};