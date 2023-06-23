//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> in(N,0);
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	        in[pre[i].second]++;
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(in[i]==0) q.push(i);
	    }
	    int count=0;
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        count++;
	        for(int i=0;i<adj[x].size();i++){
	            in[adj[x][i]]--;
	            if(in[adj[x][i]]==0) q.push(adj[x][i]);
	        }
	    }
	    if(count==N) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends