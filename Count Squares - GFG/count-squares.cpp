//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // int a=sqrt(N);
        // double b=sqrt(N);
        // if((double)a==b){
        //     return a-1;
        // }
        // return a;
        
        
        // int a=sqrt(N-1);
        // return a;
        
        long long ans;
        long long s=0;
        long long e=N-1;
        long long mid=e+(s-e)/2;
        while(s<=e){
            mid=e+(s-e)/2;
            if(mid*mid==(long long)N-1){
                ans=mid;
                break;
            }
            else if(mid*mid<N-1){
                s=mid+1;
                ans=mid;
            }
            else e=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends