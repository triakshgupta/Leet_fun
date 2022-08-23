class Solution {
public:
    bool search(vector<int> a,int s,int e,int t){
        if(s<=e){
            int mid=e+(s-e)/2;
            if(a[mid]==2*a[t] && mid!=t){
                return true;
            }
            else if(a[mid]<2*a[t] || (mid==t && a[mid]==2*a[t])){
                return search(a,mid+1,e,t);
            }
            else{
                return search(a,s,mid-1,t);
            }
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(search(arr,0,arr.size()-1,i)){
                return true;
            }
        }
        return false;
    }
};