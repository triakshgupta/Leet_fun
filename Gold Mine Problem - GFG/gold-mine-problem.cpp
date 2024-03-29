//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int path(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(j==0) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0,c;
        if(i>0) a=mat[i][j]+path(i-1,j-1,mat,dp);
        if(i<mat.size()-1) b=mat[i][j]+path(i+1,j-1,mat,dp);
        c=mat[i][j]+path(i,j-1,mat,dp);
        return dp[i][j]=max(a,max(b,c));
    }
    int maxGold(int n, int m, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=mat[i][0];
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int a=0,b=0,c;
                if(i>0) a=mat[i][j]+dp[i-1][j-1];
                if(i<mat.size()-1) b=mat[i][j]+dp[i+1][j-1];
                c=mat[i][j]+dp[i][j-1];
                dp[i][j]=max(a,max(b,c));
            }
        }
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x,dp[i][m-1]);
        }
        return x;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends