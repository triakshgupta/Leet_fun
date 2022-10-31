class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            int j=0;
            int x=i;
            int temp=matrix[j][x];
            cout<<temp<<endl;
            while(j<matrix.size() && x<matrix[0].size()){
                if(matrix[j][x]!=temp) return false;
                x++;
                j++;
            }
        }
        for(int i=0;i<matrix.size();i++){
            int j=0;
            int x=i;
            int temp=matrix[x][j];
            while(x<matrix.size() && j<matrix[0].size()){
                if(temp!=matrix[x][j]) return false;
                x++;
                j++;
            }
        }
        return true;
    }
};