class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[maxi]) maxi=i;
        }
        int c=1;
        vector<int> ans(nums.size());
        ans[maxi]=-1;
        s.push(nums[maxi]);
        while(c!=nums.size()){
            maxi--;
            if(maxi<0) maxi=nums.size()-1;
            if(s.top()>nums[maxi]) {
                ans[maxi]=s.top();
                s.push(nums[maxi]);
            }
            else{
                while(s.size()!=0 && s.top()<=nums[maxi]){
                    s.pop();
                }
                if(s.size()!=0) {
                    ans[maxi]=s.top();
                    s.push(nums[maxi]);
                }
                else{
                    ans[maxi]=-1;
                    s.push(nums[maxi]);
                }
            }
            c++;
        }
        return ans;
    }
};