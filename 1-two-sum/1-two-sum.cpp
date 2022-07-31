class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> temp;
        for(int i=0;i<nums.size();i++){
            vector<int> x={nums[i],i};
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end());
        vector<int> ans;
        int i=0,j=nums.size()-1;
        while(j>=i){
            if(temp[j][0]+temp[i][0]==target){
                ans.push_back(temp[i][1]);
                ans.push_back(temp[j][1]);
                break;
            }
            else if(temp[j][0]+temp[i][0]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};