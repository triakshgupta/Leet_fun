//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool dfs(int i,bool graph[101][101],int m,int n,vector<int>& color){
        if(i==n) return true;
        for(int j=1;j<=m;j++){
            int f=1;
            for(int k=0;k<i;k++){
                if(graph[i][k] && color[k]==j){
                    f=0;
                    break;
                }
            }
            if(f){
                color[i]=j;
                if(dfs(i+1,graph,m,n,color)) return true;
            }
            color[i]=0;
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(!dfs(i,graph,m,n,color)) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends