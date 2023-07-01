//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        if(m.size()==1) return "";
        int f=0,s=0;
        string fs,sec;
        for(auto i:m){
            if(i.second>f){
                s=f;
                sec=fs;
                f=i.second;
                fs=i.first;
            }
            else if(i.second>s){
                s=i.second;
                sec=i.first;
            }
        }
        return sec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends