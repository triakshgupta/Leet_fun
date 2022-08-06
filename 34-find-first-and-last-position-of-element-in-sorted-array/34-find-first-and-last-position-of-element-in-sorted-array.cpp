class Solution {
public:
    int fpos(vector<int> nums,int s,int e,int t){
            if(s<=e){
            int mid=e+(s-e)/2;
            if(nums[mid]==t && (mid==0 || nums[mid-1]<t)){
                return mid;
            }
            else if(nums[mid]<t){
                return fpos(nums,mid+1,e,t);
            }
            else{
                return fpos(nums,s,mid-1,t);
            }
            }
            return -1;
        }
    int lpos(vector<int> nums,int s,int e,int t){
            if(s<=e){
            int mid=e+(s-e)/2;
            if(nums[mid]==t && (mid==nums.size()-1 || nums[mid+1]>t)){
                return mid;
            }
            else if(nums[mid]>t){
                return lpos(nums,s,mid-1,t);
            }
            else{
                return lpos(nums,mid+1,e,t);
            }
            }
            return -1;
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0]=fpos(nums,0,nums.size()-1,target);
        ans[1]=lpos(nums,0,nums.size()-1,target);
        return ans;
    }
};