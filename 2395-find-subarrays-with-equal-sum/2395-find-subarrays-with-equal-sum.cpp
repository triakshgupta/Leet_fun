class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int i=0,j=0;
        map<int,int> m;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<2) j++;
            else{
                m[sum]++;
                if(m[sum]==2) return true;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return false;
    }
};