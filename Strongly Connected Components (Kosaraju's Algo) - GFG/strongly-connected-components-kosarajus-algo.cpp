//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<vector<int>>& adj1,vector<int>& vis,stack<int>& s){
	    vis[i]=1;
	    for(int j=0;j<adj1[i].size();j++){
	        if(vis[adj1[i][j]]==0){
	            dfs(adj1[i][j],adj1,vis,s);
	        }
	    }
	    s.push(i);
	}
	void dfs2(int i,vector<vector<int>>& adj1,vector<int>& vis){
	    vis[i]=1;
	    for(int j=0;j<adj1[i].size();j++){
	        if(vis[adj1[i][j]]==0){
	            dfs2(adj1[i][j],adj1,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> s;
        // vector<vector<int>> adj1(V);
        vector<vector<int>> adj2(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                adj2[adj[i][j]].push_back(i);
            }
        }
        // cout<<"x"<<endl;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0) dfs(i,adj,vis,s);
        }
        // cout<<"y"<<endl;
        vector<int> vis1(V,0);
        int scc=0;
        while(!s.empty()){
            int n=s.top();
            if(vis1[n]==0){
                scc++;
                dfs2(n,adj2,vis1);
            }
            s.pop();
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends