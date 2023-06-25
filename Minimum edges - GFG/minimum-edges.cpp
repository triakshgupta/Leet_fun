//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<vector<vector<int>>> adj(n);
            for(int i=0;i<edges.size();i++){
                adj[edges[i][0]-1].push_back({edges[i][1]-1,0});
                adj[edges[i][1]-1].push_back({edges[i][0]-1,1});
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<int> ds(n,INT_MAX);
            ds[src-1]=0;
            pq.push({0,src-1});
            while(!pq.empty()){
                int x=pq.top().second;
                int dis=pq.top().first;
                pq.pop();
                if(x==dst-1) return dis;
                for(int i=0;i<adj[x].size();i++){
                    if(ds[adj[x][i][0]]>dis+adj[x][i][1]){
                        ds[adj[x][i][0]]=dis+adj[x][i][1];
                        pq.push({ds[adj[x][i][0]],adj[x][i][0]});
                    }
                }
            }
            return -1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends