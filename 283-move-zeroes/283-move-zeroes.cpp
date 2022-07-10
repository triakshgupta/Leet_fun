class Solution {
public:
    void swap(int & a,int & b){
        int temp=a;
        a=b;
        b=temp;
    }
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                for(int j=i;j>count;j--){
                    swap(nums[j],nums[j-1]);
                }
                count++;
            }
        }
    }
};