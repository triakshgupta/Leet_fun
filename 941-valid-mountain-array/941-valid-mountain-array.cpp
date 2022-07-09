class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3 || arr[1]<arr[0]){
            return false;
        }
        int c=0;
        int prev=1;
        int curr;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                return false;
            }
            else if(arr[i+1]-arr[i]>0){
                curr=1;
                if(curr!=prev){
                    c++;
                }
                prev=curr;
            }
            else{
                curr=0;
                if(curr!=prev){
                    c++;
                }
                prev=curr;
            }
            if(c>1){
                return false;
            }
        }
        if(c!=1){
            return false;
        }
        return true;
    }
};