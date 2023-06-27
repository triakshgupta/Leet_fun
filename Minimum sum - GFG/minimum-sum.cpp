//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        string f="";
        string s="";
        int t=0;
        sort(arr,arr+n);
        int i=0;
        while(i<n){
            if(t){
                if(arr[i]!=0) s+=arr[i]+'0';
                t=0;
            }
            else{
                if(arr[i]!=0) f+=arr[i]+'0';
                t=1;
            }
            i++;
        }
        i=f.size()-1;
        int j=s.size()-1;
        int c=0;
        string ans;
        while(i>=0 && j>=0){
            int sum=(f[i]-'0')+(s[j]-'0')+c;
            c=0;
            if(sum>9) c=1;
            ans.push_back((sum%10)+'0');
            i--;
            j--;
        }
        while(i>=0){
            int sum=(f[i]-'0')+c;
            c=0;
            if(sum>9) c=1;
            ans.push_back((sum%10)+'0');
            i--;
        }
        while(j>=0){
            int sum=(s[j]-'0')+c;
            c=0;
            if(sum>9) c=1;
            ans.push_back((sum%10)+'0');
            j--;
        }
        if(c) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        if(ans.size()==0) return "0";
        return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends