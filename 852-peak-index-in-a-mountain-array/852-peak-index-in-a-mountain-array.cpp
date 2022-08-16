class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=e+((s-e)/2);
            if((mid==0 && arr[mid]>arr[1]) || (mid==arr.size()-1 && arr[mid]>arr[mid-1]) || (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])){
                return mid;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return 0;
    }
};