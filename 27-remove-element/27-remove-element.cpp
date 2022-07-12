class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> emp;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                emp.push(i);
                k++;
            }
            else{
                if(!emp.empty()){
                    nums[emp.front()]=nums[i];
                    emp.push(i);
                    emp.pop();
                }
            }
        }
        return nums.size()-k;
    }
};