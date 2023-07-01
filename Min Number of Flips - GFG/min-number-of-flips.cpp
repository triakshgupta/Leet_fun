//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int i=1;
    int p=s[0]-'0';
    int count=0;
    while(i<s.size()){
        if(s[i]==(p+'0')){
            count++;
            p=(!p);
        }
        else p=s[i]-'0';
        i++;
    }
    int c=0;
    i=1;
    p=!(s[0]-'0');
    c++;
    while(i<s.size()){
        if(s[i]==(p+'0')){
            c++;
            p=(!p);
        }
        else p=s[i]-'0';
        i++;
    }
    return min(count,c);
}