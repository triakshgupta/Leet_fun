class Solution {
public:
    int last(vector<int> nums,int target,int s,int e){
        int mid=e+(s-e)/2;
        if(s<=e){
            if((mid==nums.size()-1 || nums[mid+1]>target) && nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                return last(nums,target,s,mid-1);
            }
            else{
                return last(nums,target,mid+1,e);
            }
        }
        return -1;
    }
    int first(vector<int> nums,int target,int s,int e){
        int mid=e+(s-e)/2;
        if(s<=e){
            if((mid==0 || nums[mid-1]<target) && nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                return first(nums,target,mid+1,e);
            }
            else{
                return first(nums,target,s,mid-1);
            }
        }
        return -1;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int a=first(nums,target,0,nums.size()-1);
        int b=last(nums,target,0,nums.size()-1);
        //cout<<a<<b;
        if(a==-1){
            return ans;
        }
        else{
            for(int i=a;i<=b;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};