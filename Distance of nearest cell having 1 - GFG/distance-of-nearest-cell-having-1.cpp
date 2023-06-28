//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<int,int>> q;
	    vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),INT_MAX));
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    vector<int> dr={1,0,-1,0};
	    vector<int> dc={0,-1,0,1};
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nx=x+dr[i];
	            int ny=y+dc[i];
	            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size()){
	                if(ans[nx][ny]>ans[x][y]+1){
	                    ans[nx][ny]=ans[x][y]+1;
	                    q.push({nx,ny});
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends