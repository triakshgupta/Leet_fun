class Solution {
public:
    bool evendigit(int x){
        int c=0;
        while(x!=0){
            c++;
            x/=10;
        }
        if(c%2==0){
            return true;
        }
        return false;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(evendigit(nums[i])){
                count++;
            }
        }
        return count;
    }
};