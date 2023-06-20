//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool part(int i,int target,int arr[],int N,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==N) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool not_pick=part(i+1,target,arr,N,dp);
        bool pick=false;
        if(arr[i]<=target){
            pick=part(i+1,target-arr[i],arr,N,dp);
        }
        return dp[i][target]=(pick || not_pick);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>> dp(N,vector<int>((sum/2)+1,-1));
        return part(0,sum/2,arr,N,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends