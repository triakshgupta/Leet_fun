class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ind;
        int f=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(target-nums[i]==nums[j]){
                    f=1;
                    ind.push_back(i);
                    ind.push_back(j);
                    break;
                }
            }
            if(f==1){
                break;
            }
        }
        return ind;
        
    }
};