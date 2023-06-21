//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool path(int i,vector<vector<vector<int>>>& adj,vector<int>& vis,int dis,int k){
        if(dis>=k) return true;
        vis[i]=1;
        for(int x=0;x<adj[i].size();x++){
            if(vis[adj[i][x][0]]==0){
                if(path(adj[i][x][0],adj,vis,dis+adj[i][x][1],k)){
                    return true;
                }
            }
        }
        vis[i]=0;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
       vector<vector<vector<int>>> adj(V);
       for(int i=0;i<3*E;i+=3){
           adj[a[i]].push_back({a[i+1],a[i+2]});
           adj[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<int> vis(V,0);
       return path(0,adj,vis,0,k);
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends