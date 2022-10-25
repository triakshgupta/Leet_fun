class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        if(2*k+1>nums.size()){
            for(int i=0;i<nums.size();i++){
                ans.push_back(-1);
            }
            return ans;
        }
        long long int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            ans.push_back(-1);
        }
        int i=0,j=k;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<2*k+1){
                j++;
            }
            else{
                ans.push_back(sum/(2*k+1));
                sum-=nums[i];
                i++;
                j++;
            }
        }
        for(int x=0;x<k;x++){
            ans.push_back(-1);
        }
        return ans;
    }
};