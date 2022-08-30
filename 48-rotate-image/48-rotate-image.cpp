class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            vector<int> top;
            vector<int> right;
            vector<int> bottom;
            vector<int> left;
            for(int j=i;j<n-i;j++){
                top.push_back(matrix[i][j]);
            }
            for(int j=i;j<n-i;j++){
                right.push_back(matrix[j][n-1-i]);
                //matrix[j][n-1-i]=top[j-i];
            }
            for(int j=i;j<n-i;j++){
                bottom.push_back(matrix[n-1-i][j]);
                //matrix[n-1-i][j]=temp[temp.size()-1-(j-i)];
                //cout<<temp[temp.size()-1-(j-i)]<<endl;
            }
            for(int j=i;j<n-i;j++){
                left.push_back(matrix[j][i]);
                //matrix[j][i]=top[j-i];
            }
            for(int j=i;j<n-i;j++){
                matrix[i][j]=left[left.size()-1-(j-i)];
            }
            for(int j=i;j<n-i;j++){
                //right.push_back(matrix[j][n-1-i]);
                matrix[j][n-1-i]=top[j-i];
            }
            for(int j=i;j<n-i;j++){
                //bottom.push_back(matrix[n-1-i][j]);
                matrix[n-1-i][j]=right[right.size()-1-(j-i)];
                //cout<<temp[temp.size()-1-(j-i)]<<endl;
            }
            for(int j=i;j<n-i;j++){
                //left.push_back(matrix[j][i]);
                matrix[j][i]=bottom[j-i];
            }
        }
    }
};