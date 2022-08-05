class Solution {
public:
        int f(vector<int> nums,int e,int s){
            if(s<=e){
                int mid=e+(s-e)/2;
                if((mid==0 || nums[mid-1]>=0) && nums[mid]<0){
                   return mid;
                }
                else if(nums[mid]>=0){
                   return f(nums,e,mid+1);
                }
                else{
                   return f(nums,mid-1,s);
                }
            }
            return -1;
        }

    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int a=f(grid[i],grid[i].size()-1,0);
            if(a==-1){
                continue;
            }
            ans+=grid[i].size()-a;
        }
        return ans;
    }
};