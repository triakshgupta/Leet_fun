class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[arr.size()-1]-arr.size()<k){
            return k+arr.size();
        }
        else{
            int s=0,e=arr.size()-1;
            while(s<=e){
                int mid=e+(s-e)/2;
                if(arr[mid]-mid<=k){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            return s+k;
        }
    }
};