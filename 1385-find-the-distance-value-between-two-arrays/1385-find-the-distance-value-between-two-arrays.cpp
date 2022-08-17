class Solution {
public:
    bool bs(vector<int> a,int u,int l){
        int s=0,e=a.size()-1;
        while(s<=e){
            int mid=e+((s-e)/2);
            if(a[mid]>=u && a[mid]<=l){
                return false;
            }
            else if(a[mid]<u){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            int u=arr1[i]-d;
            int l=arr1[i]+d;
            if(bs(arr2,u,l)){
                count++;
            }
        }
        return count;
    }
};