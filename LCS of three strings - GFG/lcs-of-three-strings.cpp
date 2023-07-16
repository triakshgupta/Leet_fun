//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int lcs(int i,int j,int k,string& s,string& p,string& g,vector<vector<vector<int>>>& dp){
    if(i==-1 || j==-1 || k==-1) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(s[i]==p[j] && p[j]==g[k]){
        return dp[i][j][k]=1+lcs(i-1,j-1,k-1,s,p,g,dp);
    }
    return dp[i][j][k]=max(lcs(i-1,j,k,s,p,g,dp),max(lcs(i,j-1,k,s,p,g,dp),lcs(i,j,k-1,s,p,g,dp)));
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
    return lcs(n1-1,n2-1,n3-1,A,B,C,dp);
}