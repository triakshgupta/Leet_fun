class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int s=nums.size()/3;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second>s){
                ans.push_back(i->first);
            }
        }
        return ans;
    }
};