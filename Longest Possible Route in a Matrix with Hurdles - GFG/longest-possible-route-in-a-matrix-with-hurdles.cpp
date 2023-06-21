//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int path(int i,int j,vector<vector<int>>& matrix,int xd, int yd){
        if(i==xd && j==yd) return 0;
        int a=-1,b=-1,c=-1,d=-1;
        int temp=matrix[i][j];
        matrix[i][j]=0;
        if(i!=0 && matrix[i-1][j]!=0){
            a=path(i-1,j,matrix,xd,yd);
        }
        if(i!=matrix.size()-1 && matrix[i+1][j]!=0){
            b=path(i+1,j,matrix,xd,yd);
        }
        if(j!=0 && matrix[i][j-1]!=0){
            c=path(i,j-1,matrix,xd,yd);
        }
        if(j!=matrix[0].size()-1 && matrix[i][j+1]!=0){
            d=path(i,j+1,matrix,xd,yd);
        }
        matrix[i][j]=temp;
        int x=max(a,max(b,max(c,d)));
        if(x==-1) return -1;
        return 1+x;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys]==0 || matrix[xd][yd]==0) return -1;
        int x=path(xs,ys,matrix,xd,yd);
        // if(x>=1e5) return -1;
        return x;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends