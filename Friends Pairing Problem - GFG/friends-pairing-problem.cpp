//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
int mod=1e9+7;
    long long prs(int i,int n,vector<long long>& dp){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        long long p,np;
        p=(long long)(n-i);
        if(i<n-1) p*=prs(i+2,n,dp);
        p%=mod;
        np=prs(i+1,n,dp);
        np%=mod;
        return dp[i]=(p+np)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long> dp(n,-1);
        return prs(1,n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends