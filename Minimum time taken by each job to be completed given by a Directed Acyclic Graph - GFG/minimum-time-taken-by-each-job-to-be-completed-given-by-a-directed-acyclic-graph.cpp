//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here 
            vector<int> indeg(n+1,0);
            vector<vector<int>> adj(n+1);
            for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].push_back(edges[i][1]);
                indeg[edges[i][1]]++;
            }
            queue<pair<int,int>> q;
            for(int i=1;i<=n;i++){
                if(indeg[i]==0) q.push({i,1});
            }
            // int count=1;
            vector<int> ans(n);
            while(!q.empty()){
                int n=q.front().first;
                int t=q.front().second;
                ans[n-1]=t;
                q.pop();
                for(int i=0;i<adj[n].size();i++){
                    indeg[adj[n][i]]--;
                    if(indeg[adj[n][i]]==0){
                        q.push({adj[n][i],t+1});
                    }
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends