//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<int> dr={-1,-1,-2,-2,1,1,2,2};
    vector<int> dc={2,-2,1,-1,2,-2,1,-1};
    int steps(int i,int j,int ti,int tj,int n,vector<vector<int>>& vis){
        if(i==ti-1 && j==tj-1) return 0;
        int ans=INT_MAX;
        vis[i][j]=1;
        for(int x=0;x<8;x++){
            int nx=i+dr[x];
            int ny=j+dc[x];
            if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0){
                int a=steps(nx,ny,ti,tj,n,vis);
                if(a!=-1) ans=min(ans,a+1); 
            }
        }
        // vis[i][j]=0;
        if(ans==INT_MAX) return -1;
        return ans;
    }
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int n)
	{
	    // Code here
	    if(k[0]==t[0] && k[1]==t[1]) return 0;
	    vector<vector<int>> vis(n,vector<int>(n,0));
	    queue<vector<int>> q;
	    q.push({k[0]-1,k[1]-1,0});
	    vis[k[0]-1][k[1]-1]=1;
	    while(!q.empty()){
	        int x=q.front()[0];
	        int y=q.front()[1];
	        int step=q.front()[2];
	       // cout<<x<<" "<<y<<" "<<step<<endl;
	        q.pop();
	        for(int i=0;i<8;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0){
                    q.push({nx,ny,step+1});
                    vis[nx][ny]=1;
                    if(nx==t[0]-1 && ny==t[1]-1) return step+1;
                } 
            }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends