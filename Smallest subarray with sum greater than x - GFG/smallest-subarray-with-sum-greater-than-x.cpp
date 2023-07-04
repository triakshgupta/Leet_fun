//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        int i=0;
        int j=0;
        int val=0;
        int ans=INT_MAX;
        while(j<n){
            if(val<=x){
                val+=arr[j];
                j++;
            }
            else{
                ans=min(ans,j-i);
                while(val>x){
                    val-=arr[i];
                    i++;
                }
                ans=min(ans,j-i+1);
            }
        }
        ans=min(ans,j-i);
        while(val>x){
            val-=arr[i];
            i++;
        }
        ans=min(ans,j-i+1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends