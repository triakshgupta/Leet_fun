class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> dis;
        int f=0;
        for(int i=0;i<nums.size();i++){
            dis[nums[i]]++;
            if(dis[nums[i]]>1){
                f=1;
                break;
            }
        }
        if(f){
            return true;
        }
        return false;
    }
};