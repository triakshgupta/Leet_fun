class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            if(s.count(i)==0){
                return i;
            }
        }
        return nums.size();
    }
};