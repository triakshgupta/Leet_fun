//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<int> t(n);
        int x=n-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<0){
                t[x]=arr[i];
                x--;
            }
        }
        x=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                t[x]=arr[i];
                x++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=t[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends