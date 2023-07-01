//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.size()%2==1) return -1;
    int count=0;
    stack<char> st;
    int i=0;
    while(i<s.size()){
        if(s[i]=='{'){
            st.push('{');
        }
        else{
            if(st.size()==0){
                count++;
                st.push('{');
            }
            else st.pop();
        }
        i++;
    }
    count+=(st.size()/2);
    return count;
}