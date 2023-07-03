//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        int ind=-1;
        int count=0;
        long long val=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) val*=nums[i];
            else{
                ind=i;
                count++;
            }
        }
        if(count>=2){
            vector<long long> a(n,0);
            return a;
        }
        else if(count==1){
            vector<long long> a(n,0);
            a[ind]=val;
            return a;
        }
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            a[i]=val/nums[i];
        }
        return a;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends