//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            vector<int> dis(v,INT_MIN);
            dis[src]=0;
            vector<vector<vector<int>>> adj(v);
            for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            }
            priority_queue<pair<int,int>> q;
            q.push({0,src});
            while(!q.empty()){
                int d=q.top().first;
                int n=q.top().second;
                q.pop();
                for(int i=0;i<adj[n].size();i++){
                    if(dis[adj[n][i][0]]<d+adj[n][i][1]){
                        dis[adj[n][i][0]]=d+adj[n][i][1];
                        q.push({dis[adj[n][i][0]],adj[n][i][0]});
                    }
                }
            }
            return dis;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends