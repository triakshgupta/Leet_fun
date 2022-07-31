class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1,count=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i=j;
                count=1;
            }
            else{
                count++;
                if(count>2){
                    nums.erase(nums.begin()+j);
                    j--;
                    count--;
                }
            }
            j++;
        }
        return nums.size();
    }
};