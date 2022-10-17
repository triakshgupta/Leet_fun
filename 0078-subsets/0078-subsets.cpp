class Solution {
public:
    void subset(vector<vector<int>>& ans,vector<int>& temp,vector<int> nums,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        subset(ans,temp,nums,i+1);
        temp.push_back(nums[i]);
        subset(ans,temp,nums,i+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        subset(ans,temp,nums,0);
        return ans;
    }
};