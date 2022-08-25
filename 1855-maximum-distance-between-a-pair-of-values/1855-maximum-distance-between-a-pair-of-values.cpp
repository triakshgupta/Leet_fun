class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            int s=i,e=nums2.size()-1;
            int f=0;
            int mid=e+(s-e)/2;
            int t=nums1[i];
            while(s<=e){
               mid=e+(s-e)/2;
               if(nums2[mid]>=t && (mid==nums2.size()-1 || nums2[mid+1]<t)){
                   f=1;
                   break;
               }
               else if(nums2[mid]<t){
                   e=mid-1;
               }
               else{
                   s=mid+1;
               }
            }
            if(f){
                ans=max(ans,mid-i);
            }
        }
        return ans;
    }
};