//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans=-1;
	    int count=0;
	    for(int i=0;i<n;i++){
	        int s=0;
	        int e=m-1;
	        int mid=e+(s-e)/2;
	        while(s<=e){
	            mid=e+(s-e)/2;
	            if(arr[i][mid]==1 && (mid==0 || arr[i][mid-1]==0)){
	                break;
	            }
	            else if(arr[i][mid]==0) s=mid+1;
	            else e=mid-1;
	        }
	        if(s<=e){
	            if(count<m-mid){
	                count=m-mid;
	                ans=i;
	            }
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends