//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      vector<int> c(100001,0);
    //   int ans=1;
      for(int i=0;i<N;i++){
        c[arr[i]]=1;
      }
      int ans=1;
      int count=0;
      for(int i=0;i<c.size();i++){
          if(c[i]==1) count++;
          else{
              ans=max(count,ans);
              count=0;
          }
      }
      ans=max(count,ans);
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends