class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int col=mat.size();
        int row=mat[0].size();
        for(int i=0;i<col;i++){
            int j=i,k=0;
            vector<int> temp;
            while(j<col && k<row){
                temp.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(),temp.end());
            j=i;
            k=0;
            int z=0;
            while(j<col && k<row){
                mat[j][k]=temp[z];
                j++;
                k++;
                z++;
            }
        }
        for(int i=1;i<row;i++){
            int j=0,k=i;
            vector<int> temp;
            while(j<col && k<row){
                temp.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(),temp.end());
            j=0;
            k=i;
            int z=0;
            while(j<col && k<row){
                mat[j][k]=temp[z];
                j++;
                k++;
                z++;
            }
        }
        return mat;
    }
};