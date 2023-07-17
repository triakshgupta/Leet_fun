//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int cuts(int i,int x,int y,int z,vector<int>& dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int a=INT_MIN;
        int b=INT_MIN;
        int c=INT_MIN;
        if(i>=x){
            a=1+cuts(i-x,x,y,z,dp);
        }
        if(i>=y){
            b=1+cuts(i-y,x,y,z,dp);
        }
        if(i>=z){
            c=1+cuts(i-z,x,y,z,dp);
        }
        return dp[i]=max(a,max(b,c));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int t=cuts(n,x,y,z,dp);
        if(t<=0) return 0;
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends