//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W') {
                    dis[i][j]=0;
                    q.push({0,{i,j}});
                }
                if(c[i][j]=='N') dis[i][j]=0;
            }
        }
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};
        while(!q.empty()){
            int time=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && c[nx][ny]!='N'){
                    if(dis[nx][ny]>2*(time+1)){
                        dis[nx][ny]=2*(time+1);
                        q.push({time+1,{nx,ny}});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dis[i][j]==INT_MAX) dis[i][j]=-1;
                if(c[i][j]=='.') dis[i][j]=0;
            }
        }
        return dis;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends