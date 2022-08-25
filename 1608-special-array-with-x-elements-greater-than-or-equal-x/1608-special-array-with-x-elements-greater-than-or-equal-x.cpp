class Solution {
public:
    int search(int x,vector<int> nums,int s,int e){
        if(s<=e){
        int mid=e+(s-e)/2;
        if((nums[mid]==x && (mid==0 || nums[mid-1]!=nums[mid])) || (mid==nums.size()-1 && nums[mid]<x) || (mid!=nums.size()-1 && nums[mid]<x && nums[mid+1]>x)){
            return mid;
        }
        else if(nums[mid]>=x){
            return search(x,nums,s,mid-1);
        }
        return search(x,nums,mid+1,e);
        }
        return -1;
    }
    int specialArray(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++){
            int x=search(i,nums,0,nums.size()-1);
            if(x==-1){
                if(nums.size()==i){
                    return i;
                }
            }
            else if(nums[x]==i){
                if(nums.size()-x==i){
                    return i;
                }
            }
            else{
                if(nums.size()-x-1==i){
                    return i;
                }
            }
        }
        return -1;
    }
};