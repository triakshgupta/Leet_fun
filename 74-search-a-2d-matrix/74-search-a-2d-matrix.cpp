class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target<matrix[0][0]){
            return false;
        }
        int s=0,e=matrix.size()-1;
        int mid=e+(s-e)/2;
        while(s<=e){
            mid=e+(s-e)/2;
            if(matrix[mid][0]<=target && (mid==matrix.size()-1 || matrix[mid+1][0]>target)){
                break;
            }
            else if(matrix[mid][0]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        s=0,e=matrix[mid].size()-1;
        while(s<=e){
            int nmid=e+(s-e)/2;
            if(matrix[mid][nmid]==target){
                return true;
            }
            else if(matrix[mid][nmid]<target){
                s=nmid+1;
            }
            else{
                e=nmid-1;
            }
        }
        return false;
    }
};