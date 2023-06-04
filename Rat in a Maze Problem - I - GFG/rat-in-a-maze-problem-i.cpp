//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void path(int i,int j,string& s,vector<string>& ans,vector<vector<int>>& m,int n){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        m[i][j]=2;
        if(i!=0 && m[i-1][j]==1) {
            s+='U';
            path(i-1,j,s,ans,m,n);
            s.pop_back();
        }
        if(j!=0 && m[i][j-1]==1) {
            s+='L';
            path(i,j-1,s,ans,m,n);
            s.pop_back();
        }
        if(i!=n-1 && m[i+1][j]==1) {
            s+='D';
            path(i+1,j,s,ans,m,n);
            s.pop_back();
        }
        if(j!=n-1 && m[i][j+1]==1) {
            s+='R';
            path(i,j+1,s,ans,m,n);
            s.pop_back();
        }
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1]==0 || m[0][0]==0) return {};
        vector<string> ans;
        string s="";
        path(0,0,s,ans,m,n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends