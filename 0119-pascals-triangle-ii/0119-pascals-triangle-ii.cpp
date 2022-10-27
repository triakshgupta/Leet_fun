class Solution {
public:
    vector<int> getRow(int num) {
        vector<vector<int>> ans;
        for(int i=1;i<=num+1;i++){
            vector<int> temp;
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
                }
            }
            ans.push_back(temp);
        }
        return ans[num];
    }
};