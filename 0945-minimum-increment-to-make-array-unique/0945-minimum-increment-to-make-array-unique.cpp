class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto it:m){
            if(it.second>1){
                ans+=it.second-1;
                m[it.first+1]+=it.second-1;
            }
        }
        return ans;
    }
};