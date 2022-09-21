class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                 sum+=nums[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int ind=queries[i][1],val=queries[i][0];
            if(nums[ind]%2==0 && (nums[ind]+val)%2==0){
                sum+=val;
                nums[ind]+=val;
                ans.push_back(sum);
            }
            else if(nums[ind]%2==0 && (nums[ind]+val)%2!=0){
                sum-=nums[ind];
                nums[ind]+=val;
                ans.push_back(sum);
            }
            else if(nums[ind]%2!=0 && (nums[ind]+val)%2==0){
                sum+=nums[ind]+val;
                nums[ind]+=val;
                ans.push_back(sum);
            }
            else{
                nums[ind]+=val;
                ans.push_back(sum);
            }
        }
        return ans;
    }
};