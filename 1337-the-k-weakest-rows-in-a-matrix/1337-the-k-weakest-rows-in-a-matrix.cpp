class Solution {
public:
    int search(vector<int> a,int s,int e){
        if(s<=e){
            int mid=e+(s-e)/2;
            if(a[mid]==1 && (mid==a.size()-1 || a[mid+1]==0)){
                return mid;
            }
            else if(a[mid]==0){
                return search(a,s,mid-1);
            }
            else{
                return search(a,mid+1,e);
            }
        }
        return -1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            int count=0;
            int x=search(mat[i],0,mat[i].size()-1);
            minheap.push({x+1,i});
        }
        for(int i=0;i<k;i++){
            ans.push_back(minheap.top()[1]);
            minheap.pop();
        }
        return ans;
    }
};